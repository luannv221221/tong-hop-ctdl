#include<stdio.h>
#include<stdlib.h>
#define MAX 5
// cau truc ngan xep
typedef struct {
	int array[MAX];
	int top;
} Stack;

// khoi tao stack rong
void inital(Stack* stack) {
	stack->top = -1;
}
// ckiem tra stack co rong hay khong
int isEmpty(Stack* stack) {
	if(stack->top == -1) {
		return 1;
	}
	return 0;
}
// kiem tra ngan xep co bi day hay khong
int isFull(Stack* stack) {
	if(stack->top >= MAX - 1) {
		return 1;
	}
	return 0;
}
// them vao stack
void push(Stack* stack,int value) {
	if(isFull(stack) == 1) {
		printf("Xin Loi ngan xep da day roi ");
		return;
	}
	stack->array[++(stack->top)] = value;
}
//lay phan tu dau
void getTop(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Ngan xep rong");
	}
	printf("phan tu dau tien :%d",stack->array[(stack->top)]);
}
// xoa khoi stack pop
void pop(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Ngan xep rong");
		return;
	}

}
void printStack(Stack* stack) {
	for(int i = stack->top; i >= 0; i--) {
		printf("%d\n",stack->array[i]);
	}
}

int main() {
	int value;
	Stack stack;
	inital(&stack);
	do {
		printf("\n===============MENU==============\n");
		printf(".1 Them phan tu vao ngan xep(sep-Tung) \n");
		printf(".2 In ra ngan xep \n");
		printf("3. Lay phan tu ra khoi ngan xep \n");
		printf("4. Lay ra phan tu top cua stack \n");
		printf(".0 Thoat  \n");
		printf("Moi ban chon 0-2 ");
		int choice;
		scanf("%d",&choice);
		switch(choice) {
			case 0:
				exit(0);
			case 1:
				printf("Nhap vao gia tri can them ");
				scanf("%d",&value);
				push(&stack,value);
				break;
			case 2:
				printStack(&stack);
				break;
			case 3 :
				pop(&stack);
				break;
			case 4 :
				getTop(&stack);
				break;
			default:
				printf("Moi chon lai ");
		}
	} while(1==1);
	return 0;
}

