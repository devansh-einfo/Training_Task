#include<stdio.h>
#include<stdlib.h>
struct library{
	int qty;
	char name[50];
};
int main(){
	struct library *ptr;
	int amt;
	printf("Enter amount: ");
	scanf("%d", &amt);
	ptr = (struct library*)malloc(amt * sizeof(struct library));
	for(int i = 0; i< amt; i++){
		printf("Enter name of book: \n");
		scanf("%s %d", (ptr + i) -> name, &(ptr + i )->qty);
	}
	printf("Displaying Information: \n");
	for(int i = 0; i<amt; i++){
	printf("%s\t%d\n", (ptr + i) -> name, (ptr + i )->qty);
	}
	return 0;
}