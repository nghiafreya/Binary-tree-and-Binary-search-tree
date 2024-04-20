#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarytree.h"

int main(void) {
  // Build a binary tree
  
  Node *f = create_tree("F", NULL, NULL);
  Node *i = create_tree("I", NULL, NULL);
  Node *d = create_tree("D", f, NULL);
  Node *g = create_tree("G", NULL, NULL);
  Node *a = create_tree("A", i, d);
  Node *l = create_tree("L", NULL, g);
  Node *c = create_tree("C", a, l);
 
   /*
  printf("Ex 4-2\n");
  Node *i = create_tree("I", NULL, NULL);
  Node *e = create_tree("E", NULL, i);
  Node *d = create_tree("D", NULL, NULL);
  Node *c = create_tree("C", d, e);
  Node *g = create_tree("G", NULL, NULL);
  Node *h = create_tree("H", NULL, NULL);
  Node *f = create_tree("F", h, g);
  Node *b = create_tree("B", f, NULL);
  Node *a = create_tree("A", c, b);
  */
    
  printf("preorder: ");
  preorder(c);
  printf("\n");

  printf("inorder: ");
  inorder(c);
  printf("\n");

  printf("postorder: ");
  postorder(c);
  printf("\n");

  printf("bfs: ");
  breadth_first_search(c);
  printf("\n");

  display(c);
  printf("\n");
  printf("height: %d\n", height(c));
  
   
  printf ("\nStart creating mirror!\n");
  //create mirror nodes
  Node *mf = create_tree("F", NULL, NULL);
  Node *mi = create_tree("I", NULL, NULL);
  Node *md = create_tree("D", mf, NULL);
  Node *mg = create_tree("G", NULL, NULL);
  Node *ma = create_tree("A", mi, md);
  Node *ml = create_tree("L", NULL, mg);
  Node *mc = create_tree("C", ma, ml);
  
  create_mirror(mc);
  
  display(mc);
  printf("\n");
  
  bool result = are_mirrors(c, mc);
  printf(result ? "true" : "false");
  printf("\n");
  
  
  delete_tree(c);
  delete_tree(mc);

  return EXIT_SUCCESS;
}