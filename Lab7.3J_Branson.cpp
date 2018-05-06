// This program will read in prices and store them into a two-dimensional array.
// It will print those prices in a table form.

// Jonathan Branson - Lab7.3J_Branson.cpp
//Adapted from code provided by Dr. Stange

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXROWS = 10;
const int MAXCOLS = 10;

typedef float PriceType[MAXROWS][MAXCOLS];	// creates a new data type
											// of a 2D array of floats

void getPrices(PriceType, int&, int&);		// gets the prices into the array
void printPrices(PriceType, int, int);		// prints data as a table
float findHighestPrice(PriceType, int, int); //Find highest price
float findLowestPrice(PriceType, int, int); //Find lowest price

int main()
{
	int rowsUsed;			// holds the number of rows used
	int colsUsed;			// holds the number of columns used
	PriceType priceTable;	// a 2D array holding the prices

	getPrices(priceTable, rowsUsed, colsUsed);		// calls getPrices to fill the array
	printPrices(priceTable, rowsUsed, colsUsed);	// calls printPrices to display array

    //Finds and outputs highest price
	cout << "\nThe highest priced item is "
         << findHighestPrice(priceTable, rowsUsed, colsUsed)
         << '\n';

    //Find and outputs lowest price
    cout << "\nThe lowest priced item is "
         << findLowestPrice(priceTable, rowsUsed, colsUsed)
         << '\n';

	return 0;
}

//*******************************************************************************
//	getPrices
//
//	task:	  This procedure asks the user to input the number of rows and
//	          columns. It then asks the user to input (rows * columns) number of
//	          prices. The data is placed in the array.
//	data in:  none
//	data out: an array filled with numbers and the number of rows
//	          and columns used.
//
//*******************************************************************************

void getPrices(PriceType table, int& numOfRows, int& numOfCols)
{
	cout << "Please input the number of rows from 1 to " << MAXROWS << endl;
	cin >> numOfRows;

	cout << "\nPlease input the number of columns from 1 to " << MAXCOLS << endl;
	cin >> numOfCols;

	for (int row = 0; row < numOfRows; row++)
	{
		for (int col = 0; col < numOfCols; col++)
		{
			//Reads and stores the next value in the array
			cout << "\nInput the price of the item." << '\n';
			cin >> table[row][col];
		}
	}
}

//***************************************************************************
//	printPrices
//
//	task:	  This procedure prints the table of prices
//	data in:  an array of floating point numbers and the number of rows
//	          and columns used.
//	data out: none
//
//****************************************************************************

void printPrices(PriceType table, int numOfRows, int numOfCols)
{
	cout << fixed << showpoint << setprecision(2);

	for (int row = 0; row < numOfRows; row++)
	{
		for (int col = 0; col < numOfCols; col++)
		{
			// Prints table with width of 10
			cout << setw(10);
			cout << table[row][col];
		}
		cout << '\n';
	}
}
// This function returns the highest price in the array
float findHighestPrice(PriceType table, int numOfRows, int numOfCols)
{
    float highestPrice;
    highestPrice = table[0][0]; // make first element the highest price
    for (int row = 0; row < numOfRows; row++){

         for (int col = 0; col < numOfCols; col++){

            if ( highestPrice < table[row][col] ){

                 highestPrice = table[row][col];
            }
         }
    }
    return highestPrice;
}
// This function returns the lowest price in the array
float findLowestPrice(PriceType table, int numOfRows, int numOfCols)
{
    float highestPrice;
    highestPrice = table[0][0]; // make first element the highest price

    for (int row = 0; row < numOfRows; row++){

         for (int col = 0; col < numOfCols; col++){

            if ( highestPrice > table[row][col] ){

                highestPrice = table[row][col];
            }
         }
    }
    return highestPrice;//Actually returning lowest price
}
