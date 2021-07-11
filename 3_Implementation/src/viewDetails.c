/**
 * @file viewDetails.c
 * @author Sumit Bhimte
 * @brief Viewing specific account details by 
 *        validiating with name or account number
 * @version 0
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include "bank.h"

void viewUserDetails(void)
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float interst;
    int prog_exit;
    ptr = fopen("record.dat", "r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%1d", &choice);
    if (choice == 1)
    {
        printf("Enter the account number:");
        scanf("%d", &check.acc_no);
    
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (add.acc_no == check.acc_no)
            {
                test = 1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmp(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    interst = calculateInterest(time, add.amount, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d", interst, add.deposit.day, add.deposit.month, add.deposit.year + 1);
                }
                else if (strcmp(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    interst = calculateInterest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", interst, add.deposit.day, add.deposit.month, add.deposit.year + 2);
                }
                else if (strcmp(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    interst = calculateInterest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", interst, add.deposit.day, add.deposit.month, add.deposit.year + 3);
                }
                else if (strcmp(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    interst = calculateInterest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", interst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "current") == 0)
                {

                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }
    else if (choice == 2)
    {
        printf("Enter the name:");
        scanf("%s", check.name);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (strcmp(add.name, check.name) == 0)
            {
                test = 1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
                if (strcmp(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    interst = calculateInterest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", interst, add.deposit.day, add.deposit.month, add.deposit.year + 1);
                }
                else if (strcmp(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    interst = calculateInterest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", interst, add.deposit.day, add.deposit.month, add.deposit.year + 2);
                }
                else if (strcmp(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    interst = calculateInterest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", interst, add.deposit.day, add.deposit.month, add.deposit.year + 3);
                }
                else if (strcmp(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    interst = calculateInterest(time, add.amount, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", interst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "current") == 0)
                {
                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }
    fclose(ptr);
    if (test != 1)
    {

        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%1d", &prog_exit);

        if (prog_exit == 1)
            menu();
        else if (prog_exit == 2)
            closeProg();
        else if (prog_exit == 0)
            viewUserDetails();
        else
        {

            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%1d", &prog_exit);
    }
    if (prog_exit == 1)
    {

        menu();
    }
    else
    {
        closeProg();
    }
}
