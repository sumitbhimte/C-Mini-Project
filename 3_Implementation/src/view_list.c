/**
 * @file view_list.c
 * @author Sumit Bhimte
 * @brief Showing Full list of Account holders in bank
 * @version 0
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "bank.h"
#include<stdio.h>
#include<stdlib.h>

int view_list(int a)
{
    FILE *view;
    int prog_exit;
    view = fopen("record.dat", "r");
    int test = 0;
     
    printf("\nACC. NO.\tNAME\t\t  ADDRESS\t\tPHONE\n");

    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t %10s\t\t%10s\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }

    fclose(view);
    if (test == 0)
    {
         
        printf("\nNO RECORDS!!\n");
    }

view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &prog_exit);
     
    if (prog_exit == 1)
        menu();
    else if (prog_exit == 0)
        closeProg();
    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
     a=1;
    return a;
}