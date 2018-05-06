// This program demonstrates a compile error.
//Jonathan Branson
//Adapted from code from Dr.Melissa Stange - semiprob.cpp

#include <iostream>
using namespace std;

int main()
{
	int number;
	float total;

	cout << "Today is a great day for Lab";
	cout << endl << "Let's start off by typing a number of your choice" << endl;
	//User input
	cin >> number;

    //The equation to double user input
	total = number * 2;
	//Print out answer
	cout << total << " is twice the number you typed" << endl;

	return 0;
}
