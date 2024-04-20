#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"

int main(void) {
  // Build a binary search tree
  Node *root = NULL;
  
  /*
  insert_bst(&root, 20);
  insert_bst(&root, 10);
  insert_bst(&root, 26);
  insert_bst(&root, 14);
  insert_bst(&root, 13);
  insert_bst(&root,  5);
  */
  //Excersise 2
  printf("When tree is empty: \n");
  printf("Minimum value of this EMPTY bst: %d\n", min_bst(root));
  
  insert_bst(&root, 10);
  insert_bst(&root, 15);
  insert_bst(&root, 18);
  insert_bst(&root, 6);
  insert_bst(&root, 12);
  insert_bst(&root, 20);
  insert_bst(&root, 9);

  printf("inorder: ");
  inorder(root);
  printf("\n");

  display(root);
  printf("\n");
 /*
  if (search_bst(root, 14)) {
    printf("Found!: 14\n");
  } else {
    printf("Not found!: 14\n");
  }
  if (search_bst(root, 7)) {
    printf("Found!: 7\n");
  } else {
    printf("Not found!: 7\n");
  }
  */
  //Excersise 2
     printf("root!\n");
  if (search_bst(root, 10)) {
    printf("Found!: 10\n");
  } else {
    printf("Not found!: 10\n");
  }
  
    printf("leaf!\n");
  if (search_bst(root, 20)) {
    printf("Found!: 20\n");
  } else {
    printf("Not found!: 20\n");
  }
  
    printf("has children!\n");
  if (search_bst(root, 15)) {
    printf("Found!: 15\n");
  } else {
    printf("Not found!: 15\n");
  }
  
    printf("not in the tree!\n");
  if (search_bst(root, 8)) {
    printf("Found!: 8\n");
  } else {
    printf("Not found!: 8\n");
  }

  printf("Minimum value of this bst: %d\n", min_bst(root));

 /*
  delete_bst(&root, 10);
  printf("Value 10 deleted\n");
*/
  //excercise 2
  delete_bst(&root, 10);
  printf("Value 10 (root) deleted\n");
  
  printf("inorder: ");
  inorder(root);
  printf("\n");

  display(root);
  printf("\n");
  
  delete_bst(&root, 15);
  printf("Value 15 (parent) deleted\n");
  
  printf("inorder: ");
  inorder(root);
  printf("\n");

  display(root);
  printf("\n");

  delete_tree(root);

  return EXIT_SUCCESS;
}