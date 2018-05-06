// This program demonstrates the use of dynamic arrays

//Jonathan Branson - Lab9.3J_Branson.cpp

/*
    This program does not work and will crash when user tries to input sales, I followed
    the Sample program 9.3, but doesnt seem to work. Also nullptr is still out of scope,
    so i removed it to get program to run.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float *monthSales;	// a pointer used to point to an array
	                                // holding monthly sales

	float total = 0;	// total of all sales
	float average;		// average of monthly sales
	int numOfSales;		// number of sales to be processed
	int count;			// loop counter

	cout << fixed << showpoint << setprecision(2);

	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;

	// allocate memory for the array pointed
	monthSales = new float(numOfSales);

    //Could be the part causing the crash but can get nullptr to work
	if (monthSales = {0})
	{
		cout << "Error allocating memory!\n";
		return 1;
	}

	cout << "Enter the sales below\n";

	for (count = 0; count < numOfSales; count++)
	{
		cout << "Sales for Month number	"
		     << count+1
		     << ":" ;

		cin >> monthSales[count];//Crashing program????
		total = total + monthSales[count];
	}

	average = total/numOfSales;

	cout << "Average Monthly sale is $" << average << endl;

	delete [] monthSales;

	return 0;
}
