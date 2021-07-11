/**
 * @file changeRec.c
 * @author Sumit Bhimte
 * @brief It changes/uppdate record of exsisting customer/user
 * @version 0
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <bank.h>

void changeDetails(void)
{
    int choice, test = 0;
    int prog_exit;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%19d", &update.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no == update.acc_no)
        {
            test = 1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d", &choice);

            if (choice == 1)
            {
                printf("Enter the new address:");
                scanf("%s", update.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, update.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);

                printf("Changes saved!");
            }
            else if (choice == 2)
            {
                printf("Enter the new phone number:");
                scanf("%lf", &update.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, update.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);

                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
    {

        printf("\nRecord not found!!\a\a\a");
    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &prog_exit);

        if (prog_exit == 1)

            menu();
        else if (prog_exit == 2)
            closeProg();
        else if (prog_exit == 0)
            changeDetails();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &prog_exit);

        if (prog_exit == 1)
            menu();
        else
            closeProg();
    }
}
