#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i = 0; i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(i =0;i<n;i++){
        printf("%d ",arr[i]);

    }

    return 0;

}
    

