#include <stdio.h>  
#include <conio.h>  
#include <string.h>  
  
int upr_lwr (char *str)  
{  
    static int i = 0;  
    if (str[i])  
    {  
      
    /* If statement check the enter character's ASCII value is more than 65 and less than equal to 90. */  
        if ( str[i] >= 65 && str[i] <= 90)  
        str[i] = str[i] + 32; // add 32 to string character to change into lowercase  
        i++;  
        upr_lwr(str);   
    }  
}  
int main ()  
{  
    char str[100]; // declare the size of character array  
      
    printf (" Enter the upper case string: ");  
    gets (str); // use gets() function to take string  
      
    // call upr_lwr() function   
    upr_lwr (str);  
  
    printf (" \n The lowercase string is: %s", str);  
}  