#include<stdio.h>
void sort(int num[30], int a, int b){
    int i, j, pivot, temp;
    if(a<b){
        pivot = a;
        i = a;
        j = b;
        while(i<j){
            while(num[i]<=num[pivot]&&i<b)
                i++;
            while(num[j]>num[pivot])
                j--;
            if(i<j){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
        temp = num[pivot];
        num[pivot] = num[j];
        num[j] = temp;
        sort(num, a, j-1);
        sort(num, j+1, b);
    }
}

int main(){
    int i, count, num[30];
    printf("Enter amount of elements to be sorted:  ");
    scanf("%d", &count);
    printf("Enter %d elements: ", count);
    for(i=0;i<count;i++)
        scanf("%d", &num[i]);
    sort(num, 0, count-1);
    printf("Order of Sorted elements: ");
    for(i=0;i<count;i++)
        printf("%d ",num[i]);
    return 0;
}