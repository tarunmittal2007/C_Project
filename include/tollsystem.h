#ifndef TOLLSYSTEM_H
#define TOLLSYSTEM_H

struct VehicleRecord {
char date[20];
char vehicleNumber[20];
float amount;
char paymentMode[20];
};

void TollCollection(char *date);
void ShowHistory();
void dailyReceipt();

#endif
