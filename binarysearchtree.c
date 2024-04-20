#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarysearchtree.h"

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

Node *create_tree(int this_value, Node *this_left, Node *this_right) { 
	Node *new_node = (Node *)mallocD(sizeof(Node));
	new_node -> value = this_value;
	new_node -> left = this_left;
	new_node -> right = this_right;	
	return new_node;	 
}

void insert_bst(Node **root, int d) {	//double pointer works as 2 variables
	if (*root == NULL) { //nothing is currently poiting to root
		*root = create_tree(d, NULL, NULL);
		return;
	}
	
	Node *new_node = *root;

	while (1) {	
		if (d == new_node -> value) { //inserted 
			return;
		} else if (d > new_node -> value) {
			if (new_node -> right == NULL) {
				new_node -> right = create_tree(d, NULL, NULL);
				return;
			} else {
				new_node = new_node -> right;
			}
		} else { //d < new_node -> value
			if (new_node -> left == NULL) {
				new_node -> left = create_tree(d, NULL, NULL);
				return;
			} else {
				new_node = new_node -> left;
			}	
		}
	}	

}

void preorder(Node *n) {
	if (n == NULL) {
		return;
	}	
	printf("%d ", n -> value);
	preorder(n -> left);
	preorder(n -> right);	
}

void inorder(Node *n) { //go from leftmost node to root then go to rightmost node
	if (n == NULL) {
		return;
	}	
	inorder(n -> left); 
	printf("%d ", n -> value); //1st time: already go to the left most node
	inorder(n -> right); 
}

void postorder(Node *n) {
	if (n == NULL) {
		return;
	}	
	postorder(n -> left); 
	postorder(n -> right); 
	printf("%d ", n -> value); 
}

void display(Node *n) {
    if (n == NULL) {
        printf("null");
        return;
    }
	
    printf("%d(", n->value);
    display(n->left);
    printf(",");
    display(n->right);
    printf(")");	
    
}

void delete_bst(Node **root, int d) {
    if (*root == NULL) {
        // The tree is empty, or the value does not exist in the tree
        return;
    }

    if (d < (*root)->value) {
        // If the value to be deleted is smaller than the value of the current node, it is in the left subtree
        delete_bst(&(*root)->left, d);
    } else if (d > (*root)->value) {
        // If the value to be deleted is greater than the value of the current node, it is in the right subtree
        delete_bst(&(*root)->right, d);
    } else {
        // If the value to be deleted is the value of the current node
        Node *temp;

        // Case 1: Node has less than two children
        if ((*root)->left == NULL) {
            temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // Case 2: Node has two children
            // Find the minimum value in the right subtree to replace
            int minValue = min_bst((*root)->right);
            
            // Assign the minimum value to the current node
            (*root)->value = minValue;

            // Delete the minimum value from the right subtree
            delete_bst(&(*root)->right, minValue);
        }
    }
}

void delete_tree(Node *n) {
    if (n == NULL) {
        return; // empty tree or current node is NULL
    	}
		
	delete_tree(n -> left);
	delete_tree(n -> right);	
	free(n);
}

