             Vehicle Toll Control System
* A C-based project that manages toll collection by vehicle number , payment information , and generating daily reports.
* The system uses file handling, structures, and modular programming to efficiently record and retrieve toll data.

                   PROJECT OVERVIEW 
The Vehicle Toll Control System allows the toll booth operator to:
1. Add new toll entries (vehicle number, date, amount, payment mode)
2. Retrieve the complete history for a particular date
3. Generate a receipt of all payments collected on a specific day
4. Store all records permanently using file handling

                   PROJECT STRUCTURE 
The project is divided into multiple modules for better readability and maintenance
C_Project/
|
|__ docs/
|    |--ProjrctReport.txt
|    |--ProjectReport.pdf
|
├── src/
│   ├── main.c
│   ├── tollsystem.c
│   └── utils.c
│
├── include/
│   ├── tollsystem.h
│   └── utils.h
│
└── README.md

                  HOW TO COMPILE AND RUN : 
* Navigate to the project folder:
   cd C_Project/
* Compile the project:
   gcc src/main.c src/tollsystem.c src/utils.c -I include -o toll_system
* Run the program:
   ./tollsystem

                   TECHNOLOGIES USED 
1. C Programming Language
2. File Handling
3. Structures
4. Modular Programming
5. Standard I/O

This project is made for only learning and in future adding of many features like
* Create an admin dashboard with statistics
* Add vehicle type classification (Bike/Car/Truck)
* Export daily reports to PDF 

