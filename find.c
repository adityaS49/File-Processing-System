#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
void find_word(){
    
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
   printf("Enter the word : " );
   scanf("%s",search);

   do 
   {
      ch = fscanf(fp, "%s", word); 
      if(strcmp(word, search) == 0)
        {
         pos[count] = pointer;     
         count++;
        }
      pointer++;
      //printf("%s",word);       
   } while (ch != EOF); 

    if(count == 0)  
        printf("'%s' not found in %s\n", search, filename); 
    else
        {
        printf("'%s' is found at -> ", search);
        for(loop = 0; loop<count; loop++)
            {
                printf("%d ", pos[loop]);
            }
        printf("positions.\n");
        }
        
   fclose(fp);
   getch();

}
 
int main()
{
   find_word();

   return 0;
}