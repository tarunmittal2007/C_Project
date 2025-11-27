#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include "tollsystem.h"

// funtion to collect toll for the vehicle 
void TollCollection(char *date) 
{
struct VehicleRecord record; 
strcpy(record.date,date); // the date will remmain same for the entries of the complete day s need not to be mentionede every time 
// input all the details from the user regrding the payment and the vehicle 
printf("\n--- Toll Deduction ---\n");
printf("Enter Vehicle Number: ");
scanf("%s",record.vehicleNumber);
printf("Enter Amount: ");
scanf("%f",&record.amount);
//inplace of writing the complete string for the mode of payment , we used the numbering from 1 to 4 , to reduce the time 
int modeChoice;
printf("Select Mode of Payment:\n");
printf("1. Cash\n2. Online\n3. Fastag\n4. Valid Toll Pass\n");
printf("Enter choice: ");
scanf("%d",&modeChoice);

switch(modeChoice) 
{
case 1: strcpy(record.paymentMode, "Cash"); break;
case 2: strcpy(record.paymentMode, "Online"); break;
case 3: strcpy(record.paymentMode, "Fastag"); break;
case 4: strcpy(record.paymentMode, "TollPass"); break;
default: strcpy(record.paymentMode, "Cash"); break;
}

FILE *details = fopen("toll_records.txt","a");// open file in the append mode so that earlier data remains safe 
if(details == NULL) 
{
printf("Error opening file!\n");
return;
}
// add all the details of the new entry to the file to maintain the record 
fprintf(details,"%s | %s | %.2f | %s\n",record.date,record.vehicleNumber,record.amount,record.paymentMode);
fclose(details);
printf("Toll Deduction Recorded Successfully!\n");
}

// funtion to show all the history of the vehicle passed on that day 
void ShowHistory() 
{
char searchDate[20];
// input the date for which the history of the vehicles was required 
printf("\nEnter date to view history (DD-MM-YYYY): ");
scanf("%s",searchDate);
// open the text file in the readable format so that it can read the history from the file 
FILE *details = fopen("toll_records.txt","r");
if(details == NULL) 
{
printf("No records found!\n");
return;
}

char date[20],vehicle[20],mode[20];
float amount;
int found = 0;

printf("\n--- Toll History for %s ---\n",searchDate);
// print all the entries till the end of the file 
while(fscanf(details, "%s | %s | %f | %s",date,vehicle,&amount,mode) != EOF) 
{
if(strcmp(date,searchDate) == 0) //only print the enteries for which the date of record and the search date are same 
{
found = 1;
printf("Vehicle: %s | Amount: %.2f | Mode: %s\n",vehicle,amount,mode);
}
}

if(!found) // if there is no record for that day 
printf("No records found for this date.\n");

fclose(details);
}

// funtion to create the recipt of the daily collection amount on the basis if their mode of payment
void dailyReceipt() 
{
char searchDate[20];
printf("\nEnter date for receipt (DD-MM-YYYY): ");
scanf("%s",searchDate);

FILE *details = fopen("toll_records.txt","r"); // open the file in the readable format 
if(details == NULL) 
{
printf("No records found!\n");
return;
}
// let the initial values for each mode of payment be zero 
float cash = 0, online = 0, fastag = 0, pass = 0, amount;
char date[20], vehicle[20], mode[20];
int found = 0;

while(fscanf(details,"%s | %s | %f | %s",date,vehicle,&amount,mode) != EOF) 
{
if(strcmp(date,searchDate) == 0) 
{
found = 1;
if(strcmp(mode,"Cash") == 0) 
cash += amount;
else if(strcmp(mode,"Online") == 0) 
online += amount;
else if(strcmp(mode,"Fastag") == 0) 
fastag += amount;
else if(strcmp(mode,"TollPass") == 0) 
pass += amount;
}
}

fclose(details);

if(!found) 
{
printf("No data found for this date.\n");
return;
}

float total = cash + online + fastag + pass; // calculates the total amount collected that day 
// print all the summary in the receipt format 
printf("\n===== Toll Receipt for %s =====\n", searchDate);
printf("Cash Collection      : %.2f\n", cash);
printf("Online Collection    : %.2f\n", online);
printf("Fastag Collection    : %.2f\n", fastag);
printf("Toll Pass Collection : %.2f\n", pass);
printf("-----------------------------------\n");
printf("TOTAL COLLECTION     : %.2f\n", total);
printf("===================================\n");
}
