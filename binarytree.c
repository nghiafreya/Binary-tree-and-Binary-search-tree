#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binarytree.h"

Node *create_tree(char *this_label, Node *this_left, Node *this_right) { //because 3 keywords label, left and right also appear in struct => distinguish
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node -> label = this_label;
	new_node -> left = this_left;
	new_node -> right = this_right;	
	//printf("note %s created!\n", new_node -> label);
	return new_node;	 
}

void preorder(Node *n) {
	if (n == NULL) {
		return;
	}	
	printf("%s ", n -> label);
	preorder(n -> left);
	preorder(n -> right);	
}

void inorder(Node *n) { //go from leftmost node to root then go to rightmost node
	if (n == NULL) {
		return;
	}	
	inorder(n -> left); 
	printf("%s ", n -> label); //1st time: already go to the left most node
	inorder(n -> right); 
}

void postorder(Node *n) {
	if (n == NULL) {
		return;
	}	
	postorder(n -> left); 
	postorder(n -> right); 
	printf("%s ", n -> label); 
}


//////////////////////////////////////////
//Define enqueue and dequeue function

typedef struct queue {
  Node **buffer;
  int length;
  int front;
  int rear;
} Queue;

Queue *create_queue(int len){
	Queue *new_queue = (Queue*)malloc(sizeof(Queue));
	
	new_queue -> buffer = (Node **)malloc(sizeof(Node *) * len);	//the queue
	new_queue -> front = 0;
	new_queue -> rear = 0; 
	new_queue -> length = len;
	
	printf("\n%s\n", "Queue created!");
	return new_queue;
}


void enqueue(Queue *q, Node *d) {
	if (q -> rear > q -> length - 1) { //rear => push 
		q -> rear = 0; //make a ring buffer
	}
	
	q -> buffer[q -> rear] = d;
	q -> rear += 1;
	
}

Node *dequeue(Queue *q){
	if (q -> front > q -> length - 1) { //front => pop 
		q -> front = 0; //make a ring buffer
}	
	Node *x = q -> buffer[q -> front];
	q -> front += 1;
			
	return x;		
}

///////////////////////////////////////

 
void breadth_first_search(Node *n) {
	Queue *q = create_queue(20); //Size of queue
	enqueue (q, n);
	while ((q -> rear) > (q -> front)) { //while there is value(s) in queue
		Node *current_n = dequeue (q); 
		printf("%s ", current_n -> label);
		if (current_n -> left != NULL) {
			enqueue (q, current_n -> left);
		}
		if (current_n -> right != NULL) {
			enqueue (q, current_n -> right);
		}	
	}	
	
	free(q -> buffer);
	free(q);
	printf("\nQueue deleted!\n"); 
}

void display(Node *n) {
    if (n == NULL) {
        printf("null");
        return;
    }
	
    printf("%s(", n->label);
    display(n->left);
    printf(",");
    display(n->right);
    printf(")");	
    
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

Node *create_mirror(Node *n) {
	Node *temp;
	if (n == NULL) {
		return n;
	} else {
		create_mirror(n -> left);
		create_mirror(n -> right);
		temp = n -> left;
		n -> left = n -> right;
		n -> right = temp;		
	}
}


bool are_mirrors(Node *n0, Node *n1) {
    // leaf node
    if (n0 == NULL && n1 == NULL) {
        return true;
    }

    // One node is NULL, the other is not (both nodes are not leaf node, because leaf nodes have already been checked recently)
    if (n0 == NULL || n1 == NULL) {
        return false;
    }

    // check label
    if (strcmp(n0->label, n1->label) != 0) {
        return false;
    }

    // Both are true => return true
    return are_mirrors(n0->left, n1->right) && are_mirrors(n0->right, n1->left);
}


void delete_tree(Node *n) {
    if (n == NULL) {
        return; // empty tree or current node is NULL
    	}
		
	delete_tree(n -> left);
	delete_tree(n -> right);	
	free(n);
}


