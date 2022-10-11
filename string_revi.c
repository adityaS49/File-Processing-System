#include<stdio.h>
#include<string.h>
int main(){
    char str1[50];
    gets(str1);
    char str2[50];
    gets(str2);
    int l1,l2,i;
    l1 = strlen(str1);
    l2 = strlen(str2);

    for(i=0; str2[i]!='\0';i++);334
    {
        str1[i+l1] = str2[i];
    }
    printf("%s",str1);
    
    return 0;
}