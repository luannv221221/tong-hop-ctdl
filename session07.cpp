#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct Queue{
	int array[MAX];
	int front;
	int rear;
}Queue;

// khoi tao hang doi 
void initalQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

// kiem tra hang doi rong 
int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

// kiem tra hang doi day 
int isFull(Queue* queue){
	if(queue->rear == MAX - 1){
		return 1;
	}	
	return 0;
}

// Enqueue( Thêm phan t? vào cu?i hàng d?i.)
void enqueue(Queue* queue,int value){
	if(isFull(queue) == 1){
		printf("Xin loi het slot roi ");
		return;
	}
	if(isEmpty(queue) == 1){
		queue->front = 0;
	}
	queue->rear++;
	queue->array[queue->rear] = value;
}

int dequeue(Queue*q){
	if(q->front == -1 || q->front > q->rear){
		printf("Hang doi rong");
		return -1;
	}
	
	int temp = q->array[q->front];
	q->front++;
	return temp;
}

// display queue 
void displayQueue(Queue* queue){
	if(queue->front == -1 || queue->front > queue->rear){
		printf("Hang doi rong");
		return;
	}
	
	for(int i = queue->front; i <= queue->rear; i++){
		printf("%d \t",queue->array[i]);
	}
}

void peek(Queue* queue){
	if(queue->front == -1 || queue->front > queue->rear){
		printf("Hang doi rong");
		return;
	}
	printf("Phan tu dau tien cua hang doi : %d",queue->array[queue->front] );
}
int main(){
	Queue queue;
	initalQueue(&queue);
	int value;
	do {
		printf("\n===========MENU============\n");
		printf("0. Thoat \n");
		printf("1. Them phan tu vao cuoi hang doi \n");
		printf("2. Hien thi hang doi \n");
		printf("3. Xoa dau hang doi\n");
		printf("4. Lay ra phan tu dau tien cua hang doi\n");
		printf("Moi lua chon 0 - 2 ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 0:
				exit(0);
			case 1:
				printf("Moi ban nhap vao gia tri ");
				scanf("%d",&value);
				enqueue(&queue,value);
				break;
			case 2:
				displayQueue(&queue);
				break;
			case 3:
				dequeue(&queue);
				break;
			case 4:
				peek(&queue);
				break;
			default:
				printf("Lua chon sai roi ");
			
		}
	} while(1==1);
	return 0;
}

