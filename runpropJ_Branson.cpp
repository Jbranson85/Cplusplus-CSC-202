// This program will take a number and divide it by 2.
//Jonathan Branson
//Adapted from code from Dr.Melissa Stange - semiprob.cpp

#include <iostream>
using namespace std;

int main()
{
    //Stores input number and number to divide by
	float number;
	int divider;

    //Number that is being divided by
	divider = 2;

    //print out
	cout << "Hi there" << endl;
	cout << "Please input a number and then hit return" << endl;

	//input for users choice for a number
	cin >> number;

    //The equation to get the answer
	number = number / divider;

    //Print out answer
	cout << "Half of your number is " << number << endl;

	return 0;
}
