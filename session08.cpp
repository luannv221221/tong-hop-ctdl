#include<stdio.h>
#include<stdlib.h>

// dinh nghia 1 nut
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

// tao ra 1 nut
Node* createNode(int data) {
	// cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
// chen 1 nut vao cai cay
Node* insertNode(Node* node,int data) {
	if(node == NULL) {
		node = createNode(data);
	}
	if(data < node->data) {
		node->left = insertNode(node->left,data);
	} else if(data > node->data) {
		node->right = insertNode(node->right,data);
	}
	return node;
}
// duyet cay theo phuong phap tien thu tu
void preorderTraversal(Node* node) {
	if(node != NULL) {
		printf("%d \t",node->data);
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}

}
// trung thu tu trai-goc-phai
void inorderTraversal(Node* node) {
	if(node != NULL) {
		inorderTraversal(node->left);
		printf("%d \t",node->data);
		inorderTraversal(node->right);
	}
}

// hau thu tu trai-phai-goc
void postorderTraversal(Node* node) {
	if(node !=NULL) {
		postorderTraversal(node->left);
		postorderTraversal(node->right);
		printf("%d\t",node->data);
	}
}

// duyet cay theo chieu rong trai qua phai
int main() {
	Node* tree = NULL;
	// insert
	tree = insertNode(tree,4);
	tree = insertNode(tree,3);
	tree = insertNode(tree,6);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);



	preorderTraversal(tree);

	printf("\n");

	printf("Cay theo trung thu : \n");
	inorderTraversal(tree);
	
	printf("\n Cay theo hau thu:\n");
	postorderTraversal(tree);
	return 0;
}

