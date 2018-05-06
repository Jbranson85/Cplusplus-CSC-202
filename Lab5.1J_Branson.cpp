// This program illustrates the use of a sentinel in a while loop.
// The user is asked for monthly rainfall totals until a sentinel
// value of -1 is entered. Then the total rainfall is displayed.

// Jonathan Branson - Lab5.1J_Branson.cpp
// Adapted from code provided by Dr. Stange

#include <iostream>
using namespace std;

int main()
{
	//variables
	float total = 0, rain;
	int month = 1;

	cout << "Enter the total rainfall for month " << month << endl;
	cout << "Enter -1 when you are finished" << endl;
    //Input
	cin >> rain;


	//Loop to keep track on rain per month
	while(rain != -1)
	{
		//Updates total by adding it to rain
		total += rain;


		//Increments month by one
		month++;

		cout << "Enter the total rainfall in inches for month "
			 << month << endl;
		cout << "Enter -1 when you are finished" << endl;
        //Input
		cin >> rain;
	}
    //If statement for when -1 is pushed at the start
	if (month == 1)
		cout << "No data has been entered" << endl;

	if (month == 1)
		cout << "No data has been entered" << endl;

	else
		cout << "The total rainfall for the " << month - 1
		     << " months is " << total << " inches." << endl;

	return 0;
}
