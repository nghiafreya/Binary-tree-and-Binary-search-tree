#ifndef INCLUDE_GUARD_BINARYTREE_H
#define INCLUDE_GUARD_BINARYTREE_H

typedef struct node {
  char *label;
  struct node *left;
  struct node *right;
} Node;

Node *create_tree(char *label, Node *left, Node *right);
void preorder(Node *n);
void inorder(Node *n);
void postorder(Node *n);
void display(Node *n);
void breadth_first_search(Node *n);
int height(Node *n);
void delete_tree(Node *n);
Node *create_mirror(Node *n); //added
bool are_mirrors(Node *n0, Node *n1);
#endif  // INCLUDE_GUARD_BINARYTREE_H