#include <stdio.h>
#include "utils.h"
#include "tollsystem.h"

int main() 
{
    char date[20];
    inputDate(date);

    int choice;

    do {
        printf("\n===== Vehicle Toll Control System =====\n");
        printf("1. Toll Deduction\n");
        printf("2. Show History by Date\n");
        printf("3. Daily Receipt Summary\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                tollDeduction(date);
                break;

            case 2:
                showHistoryByDate();
                break;

            case 3:
                dailyReceipt();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}
