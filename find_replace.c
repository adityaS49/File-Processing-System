#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find and

void findAndReplaceInFile()
{
    FILE *ifp, *ofp;
    char word[100], ch, read[100], replace[100];
    int word_len, i, p = 0;
 
    ifp = fopen("somefile.txt", "r");
    ofp = fopen("file_replace_output.txt", "w+");
    if (ifp == NULL || ofp == NULL) {
        printf("Can't open file.");
        exit(0);
    }
    puts("THE CONTENTS OF THE FILE ARE SHOWN BELOW :\n");
 
    // displaying file contents
    while (1) {
        ch = fgetc(ifp);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }
 
    printf("\n\nEnter the word : ");
    scanf("%s", word);
 
    // comparing word with file
    rewind(ifp);
    while (!feof(ifp)) {
 
        fscanf(ifp, "%s", read);
 
        if (strcmp(read, word) == 0) {
 
            strupr(word);
            strcpy(read, word);
        }
 
        // In last loop it runs twice
        fprintf(ofp, "%s ", read);
    }
 
    // Printing the content of the Output file
    rewind(ofp);
    while (1) {
        ch = fgetc(ofp);
        if (ch == EOF) {
            break;
             }
        printf("%c", ch);
    }
 
    fclose(ifp);
    fclose(ofp);
}
 
// Driver code
int main()
{
    findAndReplaceInFile();
    return 0;
}