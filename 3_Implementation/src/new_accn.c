/**
 * @file new_accn.c
 * @author Sumit Bhimte
 * @brief Creates new account and details saved in records.dat file
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

void new_account()
{
    int prog_exit;
    FILE *ptr;

    ptr = fopen("record.dat", "a+");
account_no:

    printf("\nEnter the account number:");
    scanf("%d", &check.acc_no);
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!\n");
            delayProg(1000000000);
            printf("Plz Fill all information again \n");
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\nEnter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d", &add.deposit.day, &add.deposit.month, &add.deposit.year);
    printf("\nEnter the name:");
    scanf("%s", add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
    printf("\nEnter the age:");
    scanf("%d", &add.age);
    printf("\nEnter the address:");
    scanf("%s", add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s", add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f", &add.amount);
    printf("\nType of account:\n\t1.Saving\n\t2.Current\n\t3.Fixed1(for 1 year)\n\t4.Fixed2(for 2 years)\n\t5.Fixed3(for 3 years)\n\n\tEnter your choice:");

    scanf("%d", &add.type);
    switch (add.type)
    {
    case 1:
        strcpy(add.acc_type, "saving");
        break;
    case 2:
        strcpy(add.acc_type, "current");
        break;
    case 3:
        strcpy(add.acc_type, "fixed1");
        break;
    case 4:
        strcpy(add.acc_type, "fixed2");
        break;
    case 5:
        strcpy(add.acc_type, "fixed3");
        break;
    default:
        break;
    }

    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(ptr);
    printf("\nAccount created successfully!");
add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &prog_exit);

    if (prog_exit == 1)
        menu();
    else if (prog_exit == 0)
        closeProg();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}