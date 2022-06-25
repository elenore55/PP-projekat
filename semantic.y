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
  int func_cnt = -1;
  int fcall_idx = -1;
  char* func_name;

  char* arops_str[] = { "+", "-", "*", "/" };
  char* relops_str[] = { "<", ">", "<=", ">=", "==", "!=" };
%}

%code requires {
  typedef struct ast_node {
    char* name;
    unsigned type;
    unsigned kind;
    struct ast_node* children[256];
    int children_cnt;
    int index;
  } AST_NODE;

  typedef struct display_node {
    AST_NODE* node;
    int depth;
  } DISPLAY;

  AST_NODE* build_node(char* name, unsigned type, unsigned kind, unsigned children_cnt);
  AST_NODE* root;
  DISPLAY* build_display_node(AST_NODE* node, int depth);
  void print_tree(void);
  void do_semantic_analysis(AST_NODE* node);
  unsigned get_node_type(AST_NODE* node);
  void assign(AST_NODE* node);
  void arop_relop(AST_NODE* node);
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
    {
      root = $1;
    }
  ;

function_list
  : function
  | function_list function
    {
      AST_NODE* node = build_node("functions", NO_TYPE, FUNCTIONS, 2);
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
      AST_NODE* node = build_node("variables", NO_TYPE, VARIABLES, 1);
      AST_NODE* previous = $1;
      if (previous == NULL) {
        node -> children[0] = $2;
      }
      else {
        int num_children = (previous -> children_cnt) + 1;
        node -> children_cnt = num_children;
        for (int i = 0; i < num_children - 1; i++) {
          (node -> children)[i] = (previous -> children)[i];
        }
        (node -> children)[num_children - 1] = $2;
      }
      $$ = node;
    }
  ;

variable
  : _TYPE _ID _SEMICOLON
    {
      $$ = build_node($2, $1, DECL, 0);
    }
  ;

statement_list
  : /* empty */
    {
      $$ = NULL;
    }
  | statement_list statement
    {
      AST_NODE* node = build_node("statements", NO_TYPE, STATEMENTS, 1);
      AST_NODE* previous = $1;
      if (previous == NULL) {
        node -> children[0] = $2;
      }
      else {
        int num_children = (previous -> children_cnt) + 1;
        node -> children_cnt = num_children;
        for (int i = 0; i < num_children - 1; i++) {
          (node -> children)[i] = (previous -> children)[i];
        }
        (node -> children)[num_children - 1] = $2;
      }
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
      AST_NODE* node = build_node(arops_str[$2], NO_TYPE, AROP, 2);
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
      AST_NODE* node = build_node($1, NO_TYPE, FUN_CALL, 1);
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
      AST_NODE* node = build_node(relops_str[$2], NO_TYPE, RELOP, 2);
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
  node -> index = -1;
  return node;
}

DISPLAY* build_display_node(AST_NODE* node, int depth) {
  DISPLAY* display_node = (DISPLAY*) malloc(sizeof(DISPLAY));
  display_node -> node = node;
  display_node -> depth = depth;
  return display_node;
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

// TODO: check this
unsigned get_node_type(AST_NODE* node) {
  if ((node -> type) != NO_TYPE)
    return node -> type;
  if ((node -> kind) & (VAR|PAR)) {
    int i = lookup_symbol(node -> name, VAR|PAR);
    if (i == NO_INDEX) err("Undeclared %s", node -> name);
    else return get_type(i);
  }
  if (node -> children_cnt == 0) return NO_TYPE;
  unsigned types[(node -> children_cnt) + 1];
  unsigned first_type = get_node_type((node -> children)[0]);
  for (int i = 1; i < node -> children_cnt; i++) {
    unsigned next_type =get_node_type((node -> children)[i]); 
    if (next_type != first_type) 
      err("Mismatching types! %d and %d (%s)", first_type, next_type, node -> name);
  }
  return first_type;
}

void print_node(DISPLAY* display_node) {
  AST_NODE* node = display_node -> node;
  int depth = display_node -> depth;
  if (node == NULL) return;
  for (int i = 0; i < depth; i++) printf(" ");
  printf("%s\n", node -> name);
  for (int i = 0; i < node -> children_cnt; i++)
  {
    AST_NODE* next = ((node -> children)[i]);
    print_node(build_display_node(next, depth + 1));
  }
}

void print_tree(void) {
  print_node(build_display_node(root, 0));
}

void declaration(AST_NODE* node) {
  if(lookup_symbol(node -> name, VAR) != NO_INDEX) 
    err("Variable %s redeclared!", node -> name);
  int i = lookup_symbol(node -> name, VAR);
  if (i != NO_INDEX && get_atr1(i) == func_cnt) 
    err("Variable %s redeclared!", node -> name);
  insert_symbol(node -> name, VAR, node -> type, func_cnt, NO_ATR);
}

void func_declaration(AST_NODE* node) {
  if(lookup_symbol(node -> name, FUN) != NO_INDEX) 
    err("Function %s redeclared!", node -> name);
  AST_NODE* param = (node -> children)[0];
  func_name = node -> name;
  if (param == NULL) {
    insert_symbol(node -> name, FUN, node -> type, 0, NO_ATR);
  } else {
    insert_symbol(node -> name, FUN, node -> type, 1, param -> type);
    insert_symbol(param -> name, PAR, param -> type, ++func_cnt, NO_ATR);
  }
}

void assign(AST_NODE* node) {
  AST_NODE* left = (node -> children)[0];
  AST_NODE* right = (node -> children)[1];
  if (get_node_type(left) != get_node_type(right))
    err("Mismatching types!");
  if (!((left -> kind) & VAR|PAR))
    err("Invalid left side of assignement! %d", left -> kind);
}

void arop_relop(AST_NODE* node) {
  AST_NODE* left = (node -> children)[0];
  AST_NODE* right = (node -> children)[1];
  // printf("%s %d  %s %d\n", left -> name,  left -> type, right -> name, right -> type);
  if (get_node_type(left) != get_node_type(right))
    err("Mismatching types!");
}

// TODO: ako nema return a treba
void return_stm(AST_NODE* node) {
  int i = lookup_symbol(func_name, FUN);
  unsigned func_type = get_type(i);
  unsigned return_type = get_node_type(node);
  if (func_type != return_type)
    err("Invalid return value!");
}

void variable(AST_NODE* node) {
  if (lookup_symbol(node -> name, VAR|PAR) == NO_INDEX)
    err("Variable %s not declared!", node -> name);
}

void func_call(AST_NODE* node) {
  int i = lookup_symbol(node -> name, FUN);
  if (i == NO_INDEX) 
    err("Function %s not declared!", node -> name);
}

void do_semantic_analysis(AST_NODE* node) {
  if (node == NULL) return;
  switch (node -> kind) {
    case ASSIGN:
    assign(node);
    break;

    case AROP:
    case RELOP:
    arop_relop(node);
    break;

    case DECL:
    declaration(node);
    break;

    case FUN:
    func_declaration(node);
    break;

    case VAR:
    variable(node);
    break;

    case FUN_CALL:
    func_call(node);
      // check args
    break;

    case RETURN:
    return_stm(node);
    break;
  }
  for (int i = 0; i < node -> children_cnt; i++) {
    do_semantic_analysis((node -> children)[i]);
  }
}

int main() {
  int synerr;
  init_symtab();

  synerr = yyparse();

  print_tree();
  do_semantic_analysis(root);

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
