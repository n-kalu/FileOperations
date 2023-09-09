#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main()
{
    printf("\n");

    char fMenu,sMenu;

    //String to hold file name entered by the user.
    char fileName[50];

    //buffer to hold content of file
    char holdReadFile[1000];
    printf("OPTIONS:\n1 - Read File.\n2 - Create/Edit File.\n\nEnter a number: ");
    fMenu = getchar();
   
    switch (fMenu)
    {
        case '1':
            printf("\nEnter the name and extension of the file you would like to read: ");
            scanf("%s", fileName);

            //open file
            FILE *OP = fopen(fileName, "r");

            //check if file opened successfully
            if(OP == NULL)
            {
                printf("\nError! Wrong file name. Please try again.\n");
                return (1);
            }

            printf("\n\n****************** SEE CONTENTS OF FILE BELOW ****************************\n\n");

            //Read file content and save in a buffer(holdReadFile) until EOF is detected.
            //Print content of the buffer afterwards.
            while (!feof(OP))
            {
                fgets(holdReadFile, sizeof(holdReadFile), OP);
                printf("%s", holdReadFile);
            }
            
            //close the file.
            fclose(OP);

                
            break;

        case '2':
            printf("\nMORE OPTIONS:\n1 - Append new line of data.\n2 - Replace existing line of data with new data\n3 - Delete a line of data\n\nEnter a number: ");

            //clear up any character left in the Stdin buffer so the next code to read from Stdin will work.
            fgetc(stdin);

            sMenu = getchar();
            
            if(sMenu == '1')
            {
                
            }
            else if(sMenu == '2')
            {

            }
            else if(sMenu == '3')
            {

            }
            else
            {
                printf("ERROR! The number you entered is not on the Menu. Please try again.\n");
            }
            break;
        
        default:
            printf("ERROR! The number you entered is not on the Menu. Please try again.\n");
            break;
        }







    printf("\n");
    return(0);
}
