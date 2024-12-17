#include<stdio.h>
#include<stdlib.h>
#define V 4
typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* createNode(int data){
	
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

void addEdge(Node* arr[],int i, int j){
	Node* newNode = createNode(j);
	newNode->next = arr[i];
	arr[i] = newNode;
	
	newNode = createNode(i);
	newNode->next = arr[j];
	arr[j] = newNode;
}

// in ra 
void printList(Node* arr[]){
	for(int i = 0; i < V; i++){
		printf("%d :",i);
		Node* temp = arr[i];
		while(temp != NULL){
			printf("%d \t",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
int main(){
	// tao 1 do thi co 4 dinh ko canh 
	Node* adj[V];
	for(int i = 0; i < V; i++){
		adj[i] = NULL;
	}
	// them canh 
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	// in ra 
	printList(adj);
	return 0;
}

