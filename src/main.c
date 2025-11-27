#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include "utils.h"
#include "tollsystem.h"

int main() 
{
char date[20];
inputDate(date);
int choice;

do {
printf("\n===== Vehicle Toll Control System =====\n");
printf("1. Toll collection for vehicle \n");
printf("2. Show vehicle History by Date\n");
printf("3. Daily amount Receipt Summary\n");
printf("4. Exit \n");
printf("Enter your choice: ");
scanf("%d",&choice);
// here the user will enter his choice about the task he wants to perform and the same function wil be executed accordingly
switch(choice) 
{
case 1: 
TollCollection(date); 
break;
case 2: 
ShowHistory(); 
break;
case 3: 
dailyReceipt(); 
break;
case 4: 
printf("Thank You \n"); 
break;
default: 
printf("Invalid choice selected! Try again\n");
}
}while(choice != 4);// the loop will be executed until the user select 4 

return 0;
}
