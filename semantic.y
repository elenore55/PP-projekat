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

  AST_NODE* build_node(char* name, unsigned type, unsigned kind, unsigned children_cnt);
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
          argument function_list function body program statement_list statement if_statement
          if_part compound_statement assignment_statement rel_exp

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
      // TODO: kind
      AST_NODE* node = build_node("", NO_TYPE, NO_KIND, 2);
      node -> children[0] = $1;
      node -> children[1] = $2;
      $$ = node;
    }
  ;

function
  : _TYPE _ID _LPAREN parameter _RPAREN body
    {
      AST_NODE* node = build_node($2, $1, FUN, 3);      
      node -> children[0] = $4;
      node -> children[1] = $6 -> children[0];
      node -> children[2] = $6 -> children[1];
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
      $$ = build_node($2, $1, PAR, 0);
    }
  ;

body
  : _LBRACKET variable_list statement_list _RBRACKET
    {
      AST_NODE* node = build_node("", NO_TYPE, NO_KIND, 2);
      node -> children[0] = $2;
      node -> children[1] = $3;
      $$ = node; 
    }
  ;

variable_list
  : /* empty */
    {
      $$ = NULL;
    }
  | variable_list variable
    {
      // TODO: kind
      AST_NODE* node = build_node("", NO_TYPE, NO_KIND, 2);
      node -> children[0] = $1;
      node -> children[1] = $2;
      $$ = node;
    }
  ;

variable
  : _TYPE _ID _SEMICOLON
    {
      $$ = build_node($2, $1, VAR, 0);
    }
  ;

statement_list
  : /* empty */
    {
      $$ = NULL;
    }
  | statement_list statement
    {
      // TODO: kind
      AST_NODE* node = build_node("", NO_TYPE, NO_KIND, 2);
      node -> children[0] = $1;
      node -> children[1] = $2;
      $$ = node;
    }
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  ;

compound_statement
  : _LBRACKET statement_list _RBRACKET
    {
      $$ = $2;
    }
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
    {
      AST_NODE* node = build_node("=", NO_TYPE, ASSIGN, 2);
      // TODO: type
      AST_NODE* left = build_node($1, NO_TYPE, VAR|PAR, 0);
      node -> children[0] = left;
      node -> children[1] = $3;
      $$ = node;
    }
  ;

num_exp
  : exp
  | num_exp _AROP exp
    {
      AST_NODE* node = build_node("", NO_TYPE, AROP, 2);
      node -> children[0] = $1;
      node -> children[1] = $3;
      $$ = node;
    }
  ;

exp
  : literal
  | _ID
    {
      // TODO: type
      $$ = build_node($1, NO_TYPE, VAR|PAR, 0);
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
      $$ = build_node($1, INT, LIT, 0);
    }
  | _UINT_NUMBER
    {
      $$ = build_node($1, UINT, LIT, 0);
    }
  ;

function_call
  : _ID _LPAREN argument _RPAREN
    {
      // TODO: kind, type
      AST_NODE* node = build_node($1, NO_TYPE, NO_KIND, 1);
      node -> children[0] = $3;
      $$ = node;
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
    {
      $$ = $1;
    }
  | if_part _ELSE statement
    {
      AST_NODE* node = build_node("if", NO_TYPE, IF, 3);
      node -> children[0] = $1 -> children[0];
      node -> children[1] = $1 -> children[1];
      node -> children[2] = $3;
      $$ = node;
    }
  ;

if_part
  : _IF _LPAREN rel_exp _RPAREN statement
    {
      AST_NODE* node = build_node("if", NO_TYPE, IF, 2);
      node -> children[0] = $3;
      node -> children[1] = $5;
      $$ = node;
    }
  ;

rel_exp
  : num_exp _RELOP num_exp
    {
      AST_NODE* node = build_node("", NO_TYPE, RELOP, 2);
      node -> children[0] = $1;
      node -> children[1] = $3;
      $$ = node;
    }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
    {
      AST_NODE* node = build_node("return", NO_TYPE, RETURN, 1);
      node -> children[0] = $2;
      $$ = node;
    }
  ;

%%

AST_NODE* build_node(char* name, unsigned type, unsigned kind, unsigned children_cnt) {
  AST_NODE* node = (AST_NODE*) malloc(sizeof(AST_NODE));
  node -> name = name;
  node -> type = type;
  node -> kind = kind;
  node -> children_cnt = children_cnt;
  return node;
}

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
