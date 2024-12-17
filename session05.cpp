#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

Node* createNode(int data){
	// cap phat bo nho 
	Node* newNode =(Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

// thêm phan tu vao dau danh sach

void insertHead(Node** head,int data){
	// tao node moi 
	Node* newNode = createNode(data);
	newNode->next = *head;
	if(*head != NULL){
		(*head)->prev = newNode;
	}
	*head = newNode;
}

// them phan tu vao cuoi danh sach 

void insertEnd(Node** head,int data){
	Node* newNode = createNode(data);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	// tim phan tu cuoi 
	Node* temp = *head;
	
	while(temp->next != NULL){
		temp = temp->next;	
	}
	temp->next = newNode;
	newNode->prev = temp;
	
}
// Chen vao vi tri bat ky 
void insertElement(Node** head, int data, int position){
	Node* newNode = createNode(data);
	// kiem postion < 0 ko hop le 
	// vi tri position 0 ==> chen vao dau danh sach 
	
	// tim vi tri 
	if(position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	
	Node* temp = *head;
	
	for(int i=0; temp != NULL && i<position - 1; i++){
		temp = temp->next;
	}
	
	newNode->next = temp->next;
	temp->prev = newNode;
	temp->next = newNode;
	newNode->prev = temp;
}
// duyet danh sach 
void printList(Node* head){
	Node* temp = head;
	printf("NULL");
	while(temp != NULL){
		printf("<--->%d",temp->data);
		temp = temp->next;
	}
	printf("<--->NULL");
}

int main(){
	Node* head = NULL;
	int value, position;
	do{
		printf("\n==========MENU===========\n");
		printf("1. Them 1 phan tu vao dau danh sach : \n");
		printf("2. Hien thi : \n");
		printf("3. Them 1 phan tu vao cuoi danh sách : \n");
		printf("4. Them 1 phan tu vao vi tri bat ki\n");
		printf("5. Thoat : \n");
		printf("Moi ban chon tu 1 - 5: ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Moi ban nhap vao gia tri cho phan tu ");
				scanf("%d",&value);
				insertHead(&head,value);
				break;
			case 2: 
				printList(head);
				break;
			case 3:
				printf("Moi ban nhap vao gia tri can chen vao cuoi ");
				scanf("%d",&value);
				insertEnd(&head,value);
				break;
			case 4:
				printf("Moi ban nhap vi tri can chen: ");
				scanf("%d", &position);
				printf("Moi ban nhap gia tri can chen: ");
				scanf("%d", &value);
				insertElement(&head, value, position);
				break;
			case 5:
				exit(0);
			default:
				printf("Vui long nhap lai he");
		}
	} while(1 == 1);
	return 0;
}

