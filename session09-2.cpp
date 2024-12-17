#include<stdio.h>
#define MAX 100

// khai vao danh sach ke
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1;
int rear = -1;

// Ham thuem vao hang doi
void enqueue(int value) {
	if(rear == MAX - 1) {
		return;
	}
	if(front == -1) {
		front = 0;
	}
	queue[++rear] = value;
}
// lay phan tu khoi hang doi
int dequeue() {
	if(front == -1 || front > rear) {
		return -1;
	}
	return queue[front++];
}
// Thuat toan rong 
void BFSFunction(int start,int n) {
	for(int i = 0; i < n ; i++) {
		visted[i] = 0;
	}
	enqueue(start);
	visited[start] = 1;
	while(front <= rear){
		int current = dequeue();
		printf("%d",current);
		for(int i = 0;i <n;i++){
			if(graph[current][i] == 1 && !visited[i]  ){
				enqueue(i);
				visited[i]=1;
			}
		}
	}
}

// thuat toan duyet theo chieu sau

int main() {

	return 0;
}

