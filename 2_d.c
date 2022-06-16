#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[10][10], b[10][10], m[10][10], r,c,i,j,k;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);
    
    printf("Enter elements of first matrix: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter element of second matrix: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d", &b[i][j]);
        }
    }
    
    printf("Multiplication of matrix is: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            m[i][j] = 0;
            for(k=0;k<c;k++){
                m[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
