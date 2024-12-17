#include<stdio.h>
#include<stdlib.h>

// dinh nghia mot Node 
typedef struct Node{
	int data; // phan du lieu cua node 
	struct Node* next; // con tro tro den node tiep theo
} Node;

// Tao 1 Node 
Node* createNode(int value){
	// cap phat bo nho 
	Node* newNode = (Node*) malloc(sizeof(Node));
	// gan data cho node 
	newNode->data = value;
	// gan phan link
	newNode->next = NULL;
	return newNode;
} 
// them phan tu vao dau list 
void insertHead(Node** head, int value){
	// tao node moi 
	Node* newNode = createNode(value);
	// tro node mou den head 
	newNode->next = *head;
	// cap nhat head tro den node moi 
	*head = newNode;
}
// them 1 phan tu vao cuoi danh sach 
void insertEnd(Node** head, int value){
	// tao node moi 
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head; 
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

// them 1 phan tu vao vi tri bat ky 

void insertElement(Node** head,int value, int position){
	Node* newNode = createNode(value);
	if(position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	Node* temp = *head;
	for(int i = 0; i < position-1 && temp !=NULL;i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	
}
// duyet danh sach 
void printList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d--->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(){
	Node* head = NULL;
	int value;
	
	do{
		printf("=================MENU===============\n");
		printf("\n.1 Them 1 phan tu vao dau : ");
		printf("\n.2 Xem danh sach : ");
		printf("\n.3 Them 1 phan tu vao cuoi danh sach : ");
		printf("\n.4 Them 1 phan tu bat ky : ");
		printf("\n.5 Thoat : ");
		printf("\nMoi ban chon tu 1-3");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				// them mot phan tu vao dau danh sach 
				printf("Moi ban nhap vao phan tu dau");
				scanf("%d",&value);
				insertHead(&head,value);
				break;
			case 2:
					// in ra 
					printf("Danh sach ne \n"); 
					printList(head);
					break;
			case 3:
				// them 1 phan tu vao cuoi danh sach 
				printf("Moi ban nhap vao phan tu cuoi muon them");
				scanf("%d",&value);
				insertEnd(&head,value);
				break;
			case 4:
				printf("Moi vao vi tri can them ");
				int position;
				scanf("%d",&position);
				printf("Nhap vao gia tri can them ");
				scanf("%d",&value);
				insertElement(&head,value,position);
				break;
			case 5:
				exit(0);
			default:
				printf("Vui Long chon lai nhe");
		}
		
	}while(1==1);
	return 0;
}

