#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* createNode(int value) {
	Node* newNode = ((Node*)malloc(sizeof(Node)));
	newNode->data = value;
	newNode->next  =NULL;
	return newNode;
}

//them phan tu vao dau danh sach
void insertHead(Node** head, int value) {
	Node* newNode = createNode(value);
	newNode->next = *head;
	*head = newNode;

}

// them phan tu vao cuoi danh sach
void insertTail(Node** head, int value) {
	Node* newNode = createNode(value);
	if(*head == NULL) {
		return;
	}

	Node* temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}
// xóa d?u danh sách
void deleteHead(Node** head) {
	if(head == NULL) {
		printf("Rong");
		return;
	}
	Node* temp = *head;
	temp = temp->next;
	free(temp);
}
// xóa ph?n t? ? cu?i danh sách
void deleteTail(Node** head) {
	Node* temp = *head;
	if(temp == NULL) {
		printf("Roongx");
		return;
	}
	if(temp->next==NULL) {
		free(*head);
		return;
	}
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	free(temp->next);
}

int searchInList(int searchValue, Node* head) {
	Node* temp = head;
	while(temp != NULL) {
		if(temp->data == searchValue) {
			return temp->data;
		}
		temp = temp->next;
	}
	return -1;
}

void printList(Node* head) {
	Node* temp = head;
	if(temp == NULL) {
		printf("Danh sach trong");
		return;
	}
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	Node* head = NULL;
	int value, searchValue;
	do {
		printf("================ MENU ===============\n");
		printf("1. Them vao dau ds\n");
		printf("2. Them vao cuoi ds\n");
		printf("3. Xoa dau ds\n");
		printf("4. Xoa cuoi ds\n");
		printf("5. Tim kiem phan tu trong ds\n");
		printf("6. In ds\n");
		printf("0. Thoat\n");
		printf("Chon chuc nang: ");
		int choice;
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				scanf("%d", &value);
				insertHead(&head, value);
				break;
			case 2:
				scanf("%d", &value);
				insertTail(&head, value);
				break;
			case 3:
				deleteHead(&head);
				break;
			case 4:
				deleteTail(&head);
				break;
			case 5:
				scanf("%d", &searchValue);
				printf("%d\n", searchInList(searchValue, head));
				break;
			case 6:
				printList(head);
				break;
			case 0:
				exit(0);
			default:
				printf("Vui long chon lai\n");
		}
	} while(1 == 1);
	return 0;
}

