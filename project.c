#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void find_word()
{

    printf("\n----------------------------------------------------------\n");
    printf("      ***Find the Position(s) of the Word***\n");
    printf("----------------------------------------------------------\n");
    char word[50];
    char ch;
    char *filename = "somefile.txt";
    char search[100];

    int count = 0;
    int pos[1000];
    int pointer = 0;
    int loop;
    FILE *fp;
    /*  open for writing */
    fp = fopen(filename, "r");
    printf("Enter the word : ");
    scanf("%s", search);

    do
    {
        ch = fscanf(fp, "%s", word);
        if (strcmp(word, search) == 0)
        {
            pos[count] = pointer;
            count++;
        }
        pointer++;
        // printf("%s",word);
    } 
        while (ch != EOF);

    if (count == 0)
    {

        printf("'%s' not found in %s\n", search, filename);
    }

    else
    {

        printf("The Word '%s' is found %d times at position(s) -->[ ", search, count);
        for (loop = 0; loop < count; loop++)
        {
            printf("%d ", pos[loop]);
        }
        printf("].\n");
    }
    printf("\nPress Enter Key to Main Menu -->");

    fclose(fp);
    getch();
}
void count_words()
{
    int c;
    printf("\n------------------------------------\n");
    printf("      ***OPERATION***\n");
    printf("--------------------------------------\n");
    printf("1.Count Number of Words \n2.Count Number of Lines \n");
    printf("Enter your choice : ");
    scanf("%d", &c);
    FILE *ifp;
    char word[100], read[100];
    int word_len, i, p = 0;
    ifp = fopen("somefile.txt", "r");
    char chr;
    int count = 0;
    switch (c)
    {
    case 1:
    {
        printf("\n-------------------------------------------\n");
        printf("      ***Count Number of Words***\n");
        printf("------------------------------------------\n");
        while ((chr = fgetc(ifp)) != EOF)
        {
            // Counts each word
            if (chr == ' ' || chr == '\n')
                count++;
        }
        fclose(ifp);
        printf("Number of words present in given file: %d", count);
        printf("\n\nPress Enter Key to Main Menu -->");
    }
    break;
    case 2:
    {
        printf("\n-------------------------------------------\n");
        printf("      ***Count Number of Lines***\n");
        printf("------------------------------------------\n");
        for (chr = getc(ifp); chr != EOF; chr = getc(ifp))
            if (chr == '\n') // Increment count if this character is newline
                count = count + 1;

        // Close the file
        fclose(ifp);
        printf("Number of lines present in given file: %d  ", count + 1);
        printf("\n\nPress Enter Key to Main Menu -->");
    }
    break;

    default:
    {
        printf("Wrong Choice!!");
        fclose(ifp);
    }
    }
    
    getch();
    system("cls");
}

void findAndReplaceInFile()

{
    printf("\n-------------------------------------------------------\n");
    printf("      ******Find and replace the word******\n");
    printf("--------------------------------------------------------\n");
    FILE *ifp, *ofp;
    char word[100], ch, read[100], replace[100];
    int word_len, i, p = 0;

    ifp = fopen("somefile.txt", "r");
    ofp = fopen("file_replace_output.txt", "w+");
    if (ifp == NULL || ofp == NULL)
    {
        printf("Can't open file.");
        exit(0);
    }
    puts("---->THE CONTENTS OF THE FILE ARE SHOWN BELOW <----\n");

    while (1)
    {
        ch = fgetc(ifp);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
    }

    printf("\n----------------------------------------------------------------------");

    printf("\nEnter the Word to Find :-> ");
    scanf("%s", word);
    printf("----------------------------------------------------------------------\n");

    printf("Enter the Word to Replace it With :-> ");
    scanf("%s", replace);

    printf("----------------------------------------------------------------------\n");
    printf("Updated ---> [ %s --> %s ]\n\n", word, replace);

    // comparing word with file
    rewind(ifp);

    while (!feof(ifp))
    {

        fscanf(ifp, "%s", read);

        if (strcmp(read, word) == 0)
        {

            // for deleting the word
            strcpy(read, replace);
        }

        // In last loop it runs twice
        fprintf(ofp, "%s ", read);
    }

    // Printing the content of the Output file
    rewind(ofp);

    printf("The Updated content is --> \n");
    printf("----------------------------\n");

    while (1)

    {
        ch = fgetc(ofp);

        if (ch == EOF)
        {
            break;
        }

        printf("%c", ch);
    }
    printf("\n\nPress Enter Key to Main Menu -->");
    fclose(ifp);
    fclose(ofp);
    getch();
}

void change_Case()
{
    int c;
    printf("\n--------------------------------------\n");
    printf("      *****OPERATION*****\n");
    printf("--------------------------------------\n");
    printf("1. Perform Uppercase \n2. Perform Lowercase\n");
    printf("Enter your choice : ");
    scanf("%d", &c);
    FILE *ifp, *ofp;
    char word[100], ch, read[100], replace[100];
    int word_len, i, p = 0;
    ifp = fopen("somefile.txt", "r");
    ofp = fopen("file_replace_output.txt", "w+");
    switch (c)
    {
    case 1:
    {
        printf("\n---------------------------------------------\n");
        printf("      *****Perform Upper-Case*****\n");
        printf("---------------------------------------------\n");

        if (ifp == NULL || ofp == NULL)
        {
            printf("Can't open file.");
            exit(0);
        }
        puts("---->THE CONTENTS OF THE FILE ARE SHOWN BELOW <----\n");
        // displaying file contents
        while (1)
        {
            ch = fgetc(ifp);
            if (ch == EOF)
            {
                break;
            }
            printf("%c", ch);
        }
        printf("\n----------------------------------------------------------------------");

        printf("\nEnter the Lowercase Word :-> ");
        scanf("%s", word);
        printf("------------------------------------------------------------------------");
        printf("\nUpdated Content--> ");
        // comparing word with file
        rewind(ifp);
        while (!feof(ifp))
        {

            fscanf(ifp, "%s", read);

            if (strcmp(read, word) == 0)
            {

                strupr(word);
                strcpy(read, word);
            }

            // In last loop it runs twice
            fprintf(ofp, "%s ", read);
        }

        // Printing the content of the Output file
        rewind(ofp);
        while (1)
        {
            ch = fgetc(ofp);
            if (ch == EOF)
            {
                break;
            }
            printf("%c", ch);
        }
    }
    break;

    case 2:
    {
        printf("\n-----------------------------------------------\n");
        printf("      *****Perform Lower-Case*****\n");
        printf("-----------------------------------------------\n");

        if (ifp == NULL || ofp == NULL)
        {
            printf("Can't open file.");
            exit(0);
        }
        puts("---->THE CONTENTS OF THE FILE ARE SHOWN BELOW <----\n");

        // displaying file contents
        while (1)
        {
            ch = fgetc(ifp);
            if (ch == EOF)
            {
                break;
            }
            printf("%c", ch);
        }
        puts("\n--------------------------------------------------------------------------------");

        printf("Enter the Uppercase Word :-> ");
        scanf("%s", word);
        puts("-------------------------------------------------------------------------------");
        printf("Updated Content--> ");
        // comparing word with file
        rewind(ifp);
        while (!feof(ifp))
        {

            fscanf(ifp, "%s", read);

            if (strcmp(read, word) == 0)
            {

                strlwr(word);
                strcpy(read, word);
            }

            // In last loop it runs twice
            fprintf(ofp, "%s ", read);
        }

        // Printing the content of the Output file
        rewind(ofp);

        while (1)
        {
            ch = fgetc(ofp);
            if (ch == EOF)
            {
                break;
            }

            printf("%c", ch);
        }
    }
    break;
    default:
    {
        printf("Wrong Choice!!");
    }
    }

    printf("\nPress Enter Key to Main Menu -->");

    fclose(ifp);
    fclose(ofp);
    getch();
    system("cls");
}
void copy_File()

{
    char ch; // source_file[20], target_file[20];
    FILE *source, *target;
    printf("--------------------------------------------------------\n");
    printf("       ******Copy The File Operation******");
    printf("\n--------------------------------------------------------\n\n");
    printf("Enter the existing file-name :-> ");
    char source_file[50];
    scanf("%s", source_file);
    printf("Enter the name of the file to be created :-> ");
    char target_file[50];
    scanf("%s", target_file);
    printf("\n--------------------------------------------------------------------\n");
    source = fopen(source_file, "r");
    if (source == NULL)
    {
        printf("Press any key to exit...\n");
        exit(EXIT_FAILURE);
    }
    target = fopen(target_file, "w");
    if (target == NULL)
    {
        fclose(source);
        printf("Press any key to exit...\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(source)) != EOF)
        fputc(ch, target);
    printf("***File copied successfully.***\n");
    printf("\nPress Enter Key to Main Menu -->");

    fclose(source);
    fclose(target);

    getch();
}

int main()
{
    int operation = 1;

    while (operation)
    {
        printf("\n-----------------------------------------------------------------\n");
        printf("          ***** WELCOME TO FILE PROCESSING SYSTEM *****     \n");
        printf("-----------------------------------------------------------------\n");
        printf("\n1 : Find position(s) of the word\n");
        printf("2 : Count total number of Words/Lines\n");
        printf("3 : Find and Replace the Word\n");
        printf("4 : Perform Uppercase/Lowercase\n");
        printf("5 : Copy the file\n");
        printf("-------------------------\n");
        printf("Choose Operation : ");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            find_word();

            break;
        case 2:
            count_words();

            break;
        case 3:
            findAndReplaceInFile();

            break;
        case 4:
            change_Case();

            break;
        case 5:
            copy_File();

            break;
        default:
            system("cls");
            printf("\nInvalid Operation !!");
            printf("\nEnter 1,2,3,4 and 5 only");
            printf("\nEnter any key to continue");
            getch();
            system("cls");
        }
    }

    return 0;
}