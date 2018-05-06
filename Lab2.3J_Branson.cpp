// This program will output the perimeter and area
// of the rectangle with a given length and width.

//Jonathan Branson, Lab2.3J_Branson.cpp
//Adapted from code provided by Prof. Stange, circlearea.cpp

#include <iostream>
using namespace std;

const double LENGTH = 8.0;
const double WIDTH = 3.0;

int main()
{
	float area;							// definition of area of rectangle
	float perimeter;				    // definition of perimeter
	area = LENGTH * WIDTH;		        // computes area
	perimeter = 2 * (LENGTH + WIDTH);	// computes perimeter

    //Prints out the area and perimeter
    cout << "\nThe area of the rectangle is: " << area
         << "\nThe perimeter of the rectangle is: " << perimeter
         << '\n';

	return 0;
}
