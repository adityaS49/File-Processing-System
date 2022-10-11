#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
void find_word()
{

    char word[50];
    char ch;
    char *filename = "somefile.txt";
    char search[100];

    int count = 0;
    int pos[10];
    int pointer = 0;
    int loop;
    FILE *fp = NULL;
    /*  open for writing */
    fp = fopen(filename, "r");
    int i, len = 0;  
    char str[] = "";  
      
    //Calculating length of the array  
    len = sizeof(str)/sizeof(str[0]);  
      
    //Checks every character in the array  
    for(i = 0; i < len; i++){  
          
        //Checks whether a character is upper case character  
        if(isupper(str[i])){  
            //Convert that charcter to lower case  
            str[i] = tolower(str[i]);  
        }  
        //Checks whether a character is lower case character  
        else if(islower(str[i])){  
            //Convert that charcter to upper case  
            str[i] = toupper(str[i]);  
        }  
    }  
    printf("String after case conversion : %s", str);  

    fclose(fp);
    getch();
}