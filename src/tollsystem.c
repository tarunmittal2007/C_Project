#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tollsystem.h"

void tollDeduction(char *date) 
{
    struct TollRecord record;
    strcpy(record.date, date);

    printf("\n--- Toll Deduction ---\n");
    printf("Enter Vehicle Number: ");
    scanf("%s", record.vehicleNumber);
    printf("Enter Amount: ");
    scanf("%f", &record.amount);

    int modeChoice;
    printf("Select Mode of Payment:\n");
    printf("1. Cash\n2. Online\n3. Fastag\n4. Valid Toll Pass\n");
    printf("Enter choice: ");
    scanf("%d", &modeChoice);

    switch(modeChoice) 
    {
        case 1: strcpy(record.paymentMode, "Cash"); break;
        case 2: strcpy(record.paymentMode, "Online"); break;
        case 3: strcpy(record.paymentMode, "Fastag"); break;
        case 4: strcpy(record.paymentMode, "TollPass"); break;
        default: strcpy(record.paymentMode, "Cash"); break;
    }

    FILE *fp = fopen("toll_records.txt", "a");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%s | %s | %.2f | %s\n",
            record.date, record.vehicleNumber,
            record.amount, record.paymentMode);

    fclose(fp);

    printf("Toll Deduction Recorded Successfully!\n");
}

void showHistoryByDate() 
{
    char searchDate[20];
    printf("\nEnter date to view history (DD-MM-YYYY): ");
    scanf("%s", searchDate);

    FILE *fp = fopen("toll_records.txt", "r");
    if(fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    char date[20], vehicle[20], mode[20];
    float amount;
    int found = 0;

    printf("\n--- Toll History for %s ---\n", searchDate);

    while(fscanf(fp, "%s | %s | %f | %s",
                 date, vehicle, &amount, mode) != EOF)
    {
        if(strcmp(date, searchDate) == 0)
        {
            found = 1;
            printf("Vehicle: %s | Amount: %.2f | Mode: %s\n",
                   vehicle, amount, mode);
        }
    }

    if(!found)
        printf("No records found for this date.\n");

    fclose(fp);
}

void dailyReceipt() 
{
    char searchDate[20];
    printf("\nEnter date for receipt (DD-MM-YYYY): ");
    scanf("%s", searchDate);

    FILE *fp = fopen("toll_records.txt", "r");
    if(fp == NULL) 
    {
        printf("No records found!\n");
        return;
    }

    float cash = 0, online = 0, fastag = 0, pass = 0, amount;
    char date[20], vehicle[20], mode[20];
    int found = 0;

    while(fscanf(fp, "%s | %s | %f | %s",
                 date, vehicle, &amount, mode) != EOF)
    {
        if(strcmp(date, searchDate) == 0)
        {
            found = 1;

            if(strcmp(mode, "Cash") == 0) cash += amount;
            else if(strcmp(mode, "Online") == 0) online += amount;
            else if(strcmp(mode, "Fastag") == 0) fastag += amount;
            else if(strcmp(mode, "TollPass") == 0) pass += amount;
        }
    }

    fclose(fp);

    if(!found)
    {
        printf("No data found for this date.\n");
        return;
    }

    float total = cash + online + fastag + pass;

    printf("\n===== Toll Receipt for %s =====\n", searchDate);
    printf("Cash Collection      : %.2f\n", cash);
    printf("Online Collection    : %.2f\n", online);
    printf("Fastag Collection    : %.2f\n", fastag);
    printf("Toll Pass Collection : %.2f\n", pass);
    printf("-----------------------------------\n");
    printf("TOTAL COLLECTION     : %.2f\n", total);
    printf("===================================\n");
}
