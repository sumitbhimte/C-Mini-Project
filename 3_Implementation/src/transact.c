/**
 * @file transact.c
 * @author Sumit Bhimte
 * @brief It does transactions in account 
 *          1. Deposit
 *          2. Credit
 * @version 0
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

void transact(void)
{
    int choice, test = 0;
    int prog_exit;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("Enter the account no. of the customer:");
    scanf("%19d", &transaction.acc_no);
    while (fscanf(old, "%19d %59s %2d/%2d/%4d %2d %59s %14s %11lf %9s %7f %2d/%2d/%4d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {

        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            if (strcmp(add.acc_type, "fixed1") == 0 || strcmp(add.acc_type, "fixed2") == 0 || strcmp(add.acc_type, "fixed3") == 0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                delayProg(1000000000);

                menu();
            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%1d", &choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposit:$ ");
                scanf("%7f", &transaction.amount);
                add.amount += transaction.amount;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%7f", &transaction.amount);
                add.amount -= transaction.amount;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
    {
        printf("\n\nRecord not found!!");
    transact_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%1d", &prog_exit);

        if (prog_exit == 0)
            transact();
        else if (prog_exit == 1)
            menu();
        else if (prog_exit == 2)
            closeProg();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
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