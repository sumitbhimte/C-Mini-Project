/**
 * @file menu.c
 * @author Sumit Bhimte
 * @brief Shows All the menu options
 * @version 0
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "bank.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief using input choice shitch between below functions 
 *
 * @return int 
 */
int menu(void)
{
    int choice;
    int a;
    printf("\n\n\t\t\t BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t******** WELCOME TO THE MAIN MENU ********");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update info of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        new_account();
        break;
    case 2:
        changeDetails();
        break;
    case 3:
        transact();
        break;
    case 4:
        viewUserDetails();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list(a);
        break;
    case 7:
        closeProg();
        break;
    }

    return 0;
}