#include<stdio.h>

int factorial(int n);

int main(){
	// tinh n giai thua 
	int n;
	printf("Nhap vao so n ");
	scanf("%d",&n);
	int result = factorial(n);
	printf("Ket qua la %d",result);
	return 0;
}

int factorial(int n){
	// phan co so 
	if(n == 0){
		return 1;
	}
	
	// phan de quy
	// tinh n! 
	return n * factorial(n-1);
}
