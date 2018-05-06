// This program will output the circumference and area
// of the circle with a given radius.

//Jonathan Branson
//Adapted from code provided by Prof. Stange, circlearea.cpp

#include <iostream>
using namespace std;

const double PI = 3.14;
const double RADIUS = 5.4;

int main()
{
	float area;							// definition of area of circle
	int circumference;				// definition of circumference
	circumference = 2 * PI * RADIUS;	// computes circumference
	area = PI * (RADIUS * RADIUS);		// computes area

    cout << "\nThe circumference of the circle is: " << circumference
         << "\nThe area of the circle is: " << area
         << '\n';

	return 0;
}
