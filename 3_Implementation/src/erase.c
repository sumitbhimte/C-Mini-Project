/**
 * @file erase.c
 * @author Sumit Bhimte
 * @brief Delete the record of user from database of bank
 * @version 0
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include "bank.h"

void erase(void)
{
    FILE *old, *newrec;
    int prog_exit;
    int test = 0;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%19d", &removeAccn.acc_no);
    while (fscanf(old, "%19d %59s %2d/%2d/%4d %2d %59s %14s %11lf %9s %7f %2d/%2d/%4d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no != removeAccn.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);

        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test == 0)
    {
        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%1d", &prog_exit);

        if (prog_exit == 1)
            menu();
        else if (prog_exit == 2)
            closeProg();
        else if (prog_exit == 0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%1d", &prog_exit);

        if (prog_exit == 1)
            menu();
        else
            closeProg();
    }
}
