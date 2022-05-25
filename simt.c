#include<stdio.h>
#include<pthread.h>


void method(){
	int a,b, sum;
	printf("Enter a number: ");
	scanf("%d", &a);
	printf("Enter another number: ");
	scanf("%d", &b);
	sum = a + b;
	printf("Sum of both numbers is: %d ",sum);
		
}

int main(){

	pthread_t t;
	pthread_create(&t,NULL,method,NULL);
	pthread_exit(NULL);
	return 0;
}
