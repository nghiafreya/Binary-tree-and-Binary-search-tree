#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst_advanced.h"

int min_bst(Node *root) {
	if (root == NULL) return -1;
	Node *min = root;
	while (min -> left != NULL) {
		min = min -> left;
	}
	
	return min -> value;	
}

bool search_bst(Node *root, int d) {
	Node *p = root;
	
	while (p != NULL) {		
		if (p -> value == d) {
			return true;
		}
		else if (d < p -> value) {
			p = p -> left;
		} else {
			p = p -> right;
		}
	}
	return false;
}

int get_height(Node *root) {
  if (root == NULL) return 0;
  else              return root->height;
}

int reset_height(Node *root) {
  int lh = get_height(root->left);
  int rh = get_height(root->right);
  return 1 + (lh > rh ? lh : rh);
}

Node *insert_bst(Node *root, int d) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
    	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node -> value = d;
	new_node -> left = NULL;
	new_node -> right = NULL;
	return new_node;
    }

    // If the value to insert is smaller than the value at the current node, insert into the left subtree
    if (d < root->value) {
        root->left = insert_bst(root->left, d);
    }
    // If the value to insert is greater than the value at the current node, insert into the right subtree
    else if (d > root->value) {
        root->right = insert_bst(root->right, d);
    }

    // If the value to insert already exists, do nothing

    return root; // Return the tree after insertion
}




Node *delete_min_bst(Node *root) { 
	// Base case: If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }
    
	int minValue = min_bst(root);
	
	// If the current node is the one with the minimum value:
	if (minValue == root -> value){
		Node *temp = root;
		
		//that smallest node has no child:
		if (root -> right == NULL) {
			free(root);
			root = NULL; //Set the root to NULL after deletion
		} 
		//that smallest node has a right child:	
		else { 	
			root = root -> right;
			free(temp);
		}
		
	}
	// If the current node is not the one with the minimum value, move to its left child:
	else {
		 root->left = delete_min_bst(root -> left);
	}	
	return root;
 }

Node *delete_bst(Node *root, int d) {
    // Base case: If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the value to be deleted is smaller than the root's value,
    // it is in the left subtree
    if (d < root->value) {
        root->left = delete_bst(root->left, d);
    }
    // If the value to be deleted is greater than the root's value,
    // it is in the right subtree
    else if (d > root->value) {
        root->right = delete_bst(root->right, d);
    }
    // If the value to be deleted is equal to the root's value, this is the node to be deleted
    else {
        // Case 1: Node has less than two children
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node has two children
        // Find the minimum value in the right subtree to replace
        root->value = min_bst(root->right);

        // Delete the minimum value from the right subtree
        root->right = delete_min_bst(root->right);
    }

    return root; // Return the modified root
}

void inorder(Node *n) { //go from leftmost node to root then go to rightmost node
	if (n == NULL) {
		return;
	}	
	inorder(n -> left); 
	printf("%d ", n -> value); //1st time: already go to the left most node
	inorder(n -> right); 
}

int height(Node *n) {
    if (n == NULL) {
        return 0; //empty tree has height = 0, also non-existing node has value 0
    } else {
        int leftHeight = height(n->left);
        int rightHeight = height(n->right);	
        // Height of left or right tree, +1 for the root
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

void display(Node *n) {
    if (n == NULL) {
        printf("null");
        return;
    }
    
  n -> height = height(n);
    
    printf("%d#%d(", n->value, n->height);
    display(n->left);
    printf(",");
    display(n->right);
    printf(")");	
    
}


void delete_tree(Node *n) {
    if (n == NULL) {
        return; // empty tree or current node is NULL
    	}
		
	delete_tree(n -> left);
	delete_tree(n -> right);	
	free(n);
}