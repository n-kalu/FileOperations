#include <stdio.h>
#include <string.h>


int main()
{
    printf("\n");

    char fMenu,sMenu;
    //Character Array to hold file name entered by the user.
    char fileName[50];
    //buffer to hold content of file read.
    char holdReadFile[1000];
    //Buffer to hold content to be appended.
    char holdAppendFile[1000];
    //Line Number to replace or delete.
    int lineNo;
    //Current line being read
    int currentLine = 1;

    printf("OPTIONS:\n1 - Read File.\n2 - Create/Edit File.\n\nEnter a number: ");

    scanf("%c", &fMenu);

    //clear the "Stdin" buffer.
    while (getchar() != '\n'){ }
    
   
    switch (fMenu)
    {
        case '1':
            printf("\nEnter the File Name (e.g. file.txt): ");
            scanf("%s", fileName);

            //clear the "Stdin" buffer.
            while (getchar() != '\n'){ }

            //open file
            FILE *op = fopen(fileName, "r");

            //check if file opened successfully
            if(op == NULL)
            {
                printf("\nError! Wrong file name. Please try again.\n");
                return (1);
            }

            printf("\n\n****************** SEE CONTENTS OF FILE BELOW ****************************\n\n");

            //Read file content and save in a buffer(holdReadFile) until EOF is detected.
            //Print content of the buffer afterwards.
            while (fgets(holdReadFile, sizeof(holdReadFile), op))
            {
                printf("%s", holdReadFile);
            }
            
            //close the file.
            fclose(op);
            break;

        case '2':
            printf("\nMORE OPTIONS:\n1 - Append new line of text.\n2 - Replace existing line of text with new text.\n3 - Delete a line of text.\n\nEnter a number: ");

            sMenu = getchar();
            
            if(sMenu == '1')
            {
                printf("\nEnter the File Name (e.g. file.txt): ");
                scanf("%s", fileName);

                //clear the "Stdin" buffer.
                while (getchar() != '\n'){ }

                FILE *ap = fopen(fileName, "a");

                //Check that file open was successful
                if (ap == NULL)
                {
                    printf("\nError! Wrong File Name. Please try again.\n");
                    return (1);
                }
                
                //Enter text you want to append and save in the 'holdAppenFile' buffer.
                printf("\nEnter the Text you want to Append: ");
                fgets(holdAppendFile, sizeof(holdAppendFile), stdin);

                //write the text into the file
                fputs(holdAppendFile, ap);

                printf("\nSuccess!");
                
                //close file. 
                fclose(ap);    
            }
            else if(sMenu == '2')
            {
                printf("\nEnter the File Name (e.g. file.txt): ");
                scanf("%s", fileName);

                //clear the "Stdin" buffer.
                while (getchar() != '\n'){ }

                FILE *rp = fopen(fileName, "r+");

                //Check that file open was successful
                if (rp == NULL)
                {
                    printf("\nError! Wrong File Name. Please try again.\n");
                    return (1);
                }  

                // Temporary buffer to store copied/concatenated string(Character Array).
                char buf[1000];

                printf("\nEnter the Line Number you would like to Replace: ");
                scanf("%d", &lineNo);

                //clear the "Stdin" buffer.
                while (getchar() != '\n'){ }
               
                //Read file content and save in a buffer(holdReadFile) until EOF is detected.
                while (fgets(holdReadFile, sizeof(holdReadFile), rp))
                {
                    //check if current line number being read is thesame as the line number the user wants to replace.
                    if(currentLine == lineNo)
                    {
                        printf("\nEnter the text: ");
                        fgets(holdReadFile, sizeof(holdReadFile), stdin);

                        //For each iteration, copy/concatenate the character array in "holdReadFile" into a temporary buffer "buf".
                        if (currentLine == 1)
                        {
                            strcpy(buf, holdReadFile);
                        }
                        else
                        {
                            strcat(buf, holdReadFile);
                        }
                        currentLine++;
                        continue;
                    }
                    
                    //For each iteration, copy/concatenate the character array in "holdReadFile" into "buf"
                    if (currentLine == 1)
                    {
                        strcpy(buf, holdReadFile);
                    }
                    else
                    {
                        strcat(buf, holdReadFile);
                    }
                    
                    currentLine++;

                }

                //Set file pointer to point to the begining/first character of the file.
                fseek(rp,0,SEEK_SET);

                //Replace existing text in file with concatenated string saved in the "buf" temporary buffer.
                fprintf(rp, "%s", buf);
                
                //print out the result on the screen as well.
                printf("\n\n******************* SEE UPDATED CONTENT OF FILE BELOW ***********************\n\n");
                printf("%s", buf);

                //Close file.
                fclose(rp);

            }
            else if(sMenu == '3')
            {
                printf("\nEnter the File Name (e.g. file.txt): ");
                scanf("%s", fileName);

                //clear the "Stdin" buffer.
                while (getchar() != '\n'){ }

                FILE *de = fopen(fileName, "r");

                //Check that file open was successful.
                if (de == NULL)
                {
                    printf("\nError! Wrong File Name. Please try again.\n");
                    return (1);
                }  

                // Temporary buffer to store copied/concatenated string(Character Array).
                char buf[1000];

                printf("\nEnter the Line Number you would like to Delete: ");
                scanf("%d", &lineNo);
                
                //clear the "Stdin" buffer.
                while (getchar() != '\n'){ }
                           
                //Read file content and save in a buffer(holdReadFile) until EOF is detected.
                while (fgets(holdReadFile, sizeof(holdReadFile), de))
                {
                    //check if current line number being read is thesame as the line number the user wants to replace.
                    if(currentLine == lineNo)
                    {
                        currentLine++;
                        continue;
                    }

                    //For each iteration, copy/concatenate the character array in "holdReadFile" into "buf"
                    if (currentLine == 1)
                    {
                        strcpy(buf, holdReadFile);
                    }
                    else
                    {
                        strcat(buf, holdReadFile);
                    }                    
                    
                    currentLine++;

                }
                //Close file.
                fclose(de);

                //Open file and clear content in file.
                FILE *dw = fopen(fileName, "w");
                //write string saved in the "buf" temporary buffer into the.
                fprintf(dw, "%s", buf);
                
                //print out the result on the screen as well.
                printf("\n\n******************* SEE UPDATED CONTENT OF FILE BELOW ***********************\n\n");
                printf("%s", buf);

                //Close file.
                fclose(dw);

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
