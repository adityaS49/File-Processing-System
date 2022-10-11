#include<stdio.h>
int main(){
    int row,col , i,j;
    printf("Enter the number of row: ");
     scanf("%d",&row);
    
    printf("Enter the number of col: ");
     scanf("%d",&col);
   
   int arr[row][col];
   printf("Enter the elements of the array : ");
   for ( i = 0; i < row; i++){
    for ( j = 0; j < col; j++)
    {
        scanf("%d",&arr[i][j]);
    }
   }
   printf("Elements of the array are:\n");
   for ( i = 0; i < row; i++){
    for ( j = 0;j < col; j++)
    {
         printf(" %d",arr[i][j]);
    }
    printf("\n");
   }
   
    return 0;
}