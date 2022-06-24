%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "ast_node.h"
  #include "defs.h"
  #include "symtab.h"


  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  extern int yylineno;
%}

%union {
  int i;
  char* s;
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

%type <n> literal variable variable_list parameter

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : function_list
  ;

function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID _LPAREN parameter _RPAREN body
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
  : /* empty Skontati sta ovdje za cvor*/
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
  ;

exp
  : literal
  | _ID
  | function_call
  | _LPAREN num_exp _RPAREN
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
  ;

argument
  : /* empty */
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
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  return 0;
}

int main() {
  return yyparse();
}
