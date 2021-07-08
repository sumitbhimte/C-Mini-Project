/**
 * @file main.c
 * @author Sumit Bhimte
 * @brief Main function of the program
 * @version 0
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

int prog_exit;

int main()
{
    char Userpass[10];
    char password[10] = "root";
    printf("\n\n\t\tDefault Password is \"root\"");
    printf("\n\t\tEnter the password to login:");
    scanf("%9s", Userpass);

    if (strcmp(Userpass, password) == 0)
    {
        printf("\n\n\t\tPassword Match!\n");
        printf("LOADING");
        for (int i = 0; i <= 5; i++)
        {
            delayProg(100000000);
            printf(".");
        }

        menu();
    }
    else
    {
        printf("\n\nWrong password!!");
        printf("\a\a\a");
    login_stmt:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%1d", &prog_exit);
        if (prog_exit == 1)
        {

            main();
        }

        else if (prog_exit == 0)
        {
            closeProg();
        }
        else
        {
            printf("\nInvalid!");
            delayProg(1000000000);

            goto login_stmt;
        }
    }
    return 0;
}
