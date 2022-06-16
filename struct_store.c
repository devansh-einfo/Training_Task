#include<stdio.h>
#include<stdlib.h>
struct student {
    char fname[100];
    int roll;
    float marks;
} s[10];

int main(){
    int i,n;
    
    printf("Enter amount of students in your class: ");
    scanf("%d", &n);
    printf("Enter student information: \n");
    
    for(i=0;i<n;i++){
        s[i].roll = i+1;
        printf("Roll Number: %d\n", s[i].roll);
        printf("Enter First Name: ");
        scanf("%s", s[i].fname);
        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("\nDisplaying Information:\n");
    for(i=0;i<n;i++){
        printf("\nRoll Number: %d\n", i+1);
        printf("First Name: ");
        puts(s[i].fname);
        printf("Marks: %.1f", s[i].marks);
    }
    return 0;
}