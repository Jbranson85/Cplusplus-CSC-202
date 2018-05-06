// This program will read in the quarterly sales transactions for a given number
// of years. It will print the year and transactions in a table format.
// It will calculate year and quarter total transactions.

// Jonathan Branson - Lab 7.3#5J_Branson.cpp
//Adapted by coded provided by Dr. Stange

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXYEAR = 10;
const int MAXCOL = 5;

typedef int SalesType[MAXYEAR][MAXCOL];	// creates a new 2D integer data type

void getSales(SalesType, int&);		// places sales figures into the array
void printSales(SalesType, int);	// prints data as a table
void printTableHeading();			// prints table heading

int main()
{
	int yearsUsed;		// holds the number of years used
	SalesType sales;	// 2D array holding the sales transactions

	getSales(sales, yearsUsed);		// calls getSales to put data in array
	printTableHeading();			// calls procedure to print the heading
	printSales(sales, yearsUsed);	// calls printSales to display table

	return 0;
}

//*****************************************************************************
//	printTableHeading
//
//	task:	  This procedure prints the table heading
//	data in:  none
//	data out: none
//
//*****************************************************************************

void printTableHeading()
{
	cout << '\n' << setw(45) << "YEARLY QUARTERLY SALES" << endl << endl << endl;

	cout << setw(12) << "YEAR" << setw(12) << "Quarter 1"
		 << setw(12) << "Quarter 2" << setw(12) << "Quarter 3"
		 << setw(12) << "Quarter 4" << endl;
}

//*****************************************************************************
//	getSales
//
//	task:	  This procedure asks the user to input the number of years.
//	          For each of those years it asks the user to input the year
//	          (e.g. 2004), followed by the sales figures for each of the
//	          4 quarters of that year. That data is placed in a 2D array
//	data in:  a 2D array of integers
//	data out: the total number of years
//
//*****************************************************************************

void getSales(SalesType	table, int&	numOfYears)
{

	cout << "Please input the number of years (1-" << MAXYEAR << ")" << endl;
	cin >> numOfYears;

	//reads and stores the next value
	for (int x = 0; x < numOfYears; x++){

        cout << "\nWhat was the year of the transaction? ";
        cin >> table[x][0];

        //Variable used for do while loop
        int y = 1;
        //Loop to get all transactions for the quarter
        do{
             cout << "\nHow many transaction occurred for the Quarter "
             << y << " in year " << table[x][0]
             << '\n';
             cin >> table[x][y];
            y++;//Add 1 to y

        }while(y < MAXCOL);//end loop when y not longer < MAXCOL(5)

	}
}

//*****************************************************************************
//	printSales
//
//	task:	  This procedure prints out the information in the array
//	data in:  an array containing sales information
//	data out: none
//
//*****************************************************************************

void printSales(SalesType table, int numOfYears)
{

	//Variable used for do while loop
	int x = 0;
    //Loop to print table
	do{

        cout << setw(12) << table[x][0] << setw(12) << table[x][1]
             << setw(12) << table[x][2] << setw(12) << table[x][3]
             << setw(12) << table[x][4]
             << '\n';
             x++;//Add 1 to x

	}while(x < numOfYears);//End loop when x no longer < numOfYears

}
