#ifndef AST_NODE_H
#define AST_NODE_H

typedef struct ast_node {
   char* name;
   unsigned type;
   unsigned kind;
   struct ast_node* children[256];
   int children_cnt;
} AST_NODE;

#endif