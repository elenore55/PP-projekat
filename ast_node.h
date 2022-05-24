typedef struct ast_node {
   char* name;
   char op;
   char* value;
   AST_NODE* children[256];
   int children_cnt;
} AST_NODE;