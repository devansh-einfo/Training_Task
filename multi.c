#include<stdio.h>
#include<pthread.h>

void *method_one(void *n){
	int num = (int *) n;
	printf("Thread running: %d\n", num);
}

int main(){
	printf("Main function Running\n");
	pthread_t t[3];
	for(int i=1;i<=3;i++){
		pthread_create(&t[i],NULL,(void *)method_one,i);
	}
	printf("Main function stopped\n");
	pthread_exit(NULL);
	return 0;
}
