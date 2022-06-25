%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
%}

%code requires {
  typedef struct ast_node {
    char* name;
    unsigned type;
    unsigned kind;
    struct ast_node* children[256];
    int children_cnt;
  } AST_NODE;
}

%union {
  int i;
  char *s;
  AST_NODE* n;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP

%type <n> literal variable variable_list parameter return_statement exp num_exp function_call
          argument function_list function

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : function_list
  ;

function_list
  : function
  | function_list function
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> children_cnt = 2;
      node -> children[0] = $1;
      node -> children[1] = $2;
      $$ = node;
    }
  ;

function
  : _TYPE _ID _LPAREN parameter _RPAREN body
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> name = $2;
      node -> type = $1;
      node -> kind = FUN;
      node -> children_cnt = 2;

      AST_NODE* node_left = (AST_NODE*) malloc(sizeof(AST_NODE));
      
      AST_NODE* node_right = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> children[0] = node_left;
      node -> children[1] = node_right;
      $$ = node;
    }
  ;

parameter
  : /* empty */
    {
      $$ = NULL;
    }
  | _TYPE _ID
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> name = $2;
      node -> type = $1;
      node -> kind = PAR;
      $$ = node;
    }
  ;

body
  : _LBRACKET variable_list statement_list _RBRACKET
  ;

variable_list
  : /* empty */
    {
      $$ = NULL;
    }
  | variable_list variable
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      AST_NODE* child1 = $1;
      AST_NODE* child2 = $2;
      node -> children[0] = $1;
      node -> children[1] = $2;
      node -> children_cnt = 2;
      $$ = node;
    }
  ;

variable
  : _TYPE _ID _SEMICOLON
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> name = $2;
      node -> type = $1;
      node -> kind = VAR;
      $$ = node;
    }
  ;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  ;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
  ;

num_exp
  : exp
  | num_exp _AROP exp
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> kind = AROP;
      node -> children_cnt = 2;
      node -> children[0] = $1;
      node -> children[1] = $3;
      $$ = node;
    }
  ;

exp
  : literal
  | _ID
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> name = $1;
      node -> kind = VAR|PAR;
      // TODO: node -> type = ?
      $$ = node;
    }
  | function_call
  | _LPAREN num_exp _RPAREN
    {
      $$ = $2;
    }
  ;

literal
  : _INT_NUMBER
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> name = $1;
      node -> type = UINT;
      node -> kind = LIT;
      $$ = node;
    }
  | _UINT_NUMBER
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> name = $1;
      node -> type = UINT;
      node -> kind = LIT;
      $$ = node;
    }
  ;

function_call
  : _ID _LPAREN argument _RPAREN
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> name = $1;
      // TODO: kind, type
      node -> children_cnt = 1;
      node -> children[0] = $3;
    }
  ;

argument
  : /* empty */
    {
      $$ = NULL;
    }
  | num_exp
  ;

if_statement
  : if_part %prec ONLY_IF
  | if_part _ELSE statement
  ;

if_part
  : _IF _LPAREN rel_exp _RPAREN statement
  ;

rel_exp
  : num_exp _RELOP num_exp
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
    {
      AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
      node -> kind = RETURN;
      node -> children_cnt = 1;
      node -> children[0] = $2;
      $$ = node;
    }
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();

  synerr = yyparse();

  clear_symtab();
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr)
    return -1; //syntax error
  else
    return error_count; //semantic errors
}
