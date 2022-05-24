typedef struct ast_node {
   char* name;
   char op;
   char* value;
   struct ast_node* children[256];
   int children_cnt;
} AST_NODE;