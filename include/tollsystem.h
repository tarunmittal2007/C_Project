#ifndef TOLLSYSTEM_H
#define TOLLSYSTEM_H

// structure of toll record
struct TollRecord {
    char date[20];
    char vehicleNumber[20];
    float amount;
    char paymentMode[20];
};

void tollDeduction(char *date);
void showHistoryByDate();
void dailyReceipt();

#endif
