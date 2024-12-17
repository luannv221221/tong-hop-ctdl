#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode){
		printf("Khong the cap phat bo nho");
		exit(1);
	}else{
		newNode->data = value;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	return newNode;
}
void insertAtHead(Node** head, int data){
	Node* newNode = createNode(data);
	newNode->next = *head;
	if(*head != NULL){
		
		(*head)->prev = newNode;
	};
	*head = newNode;
};
void insertAtTail(Node** head, int data){
	Node *newNode = createNode(data);
	if(*head == NULL){
		*head = newNode;
		return;
	};
	Node* temp = *head;
	while(temp != NULL){
		temp->next = temp;
	}
	temp->next = newNode;
	newNode->prev = temp;
	
};

void deleteHead(Node** head) {
	if(head == NULL) {
		return;
	}
	Node* temp = *head;
	*head = temp->next;
	if(*head != NULL) {
		(*head)->prev = NULL;
	}
}

void deleteEnd(Node** head) {
	if(head == NULL) {
		return;
	}
	Node* temp = *head;
	if(temp->next == NULL) {
		*head = NULL;
		return;
	}
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->prev->next = NULL;
}

void printForward(Node*head){
	Node*temp = head;
	while(temp != NULL){
		printf("%d<->", temp->data);
		temp = temp->next;
	}
	printf("NULL");
}

void printBackward(Node*tail){
	Node*temp = tail;
	while(temp != NULL){
		printf("%d<->", temp->data);
		temp = temp->prev;
	}
	printf("NULL");
}

int main(){
	Node*head = NULL;
	Node*tail = NULL;
	
	insertAtHead(&head, 1);
	insertAtTail(&head,5);
	
	printf("duyet tu dau mang: ");
	printForward(head);
	printf("/n duyet tu cuoi mang: ");
	printBackward(tail);
	
	
	

	return 0;
}

