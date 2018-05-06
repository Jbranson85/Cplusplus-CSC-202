// This program demonstrates the use of pointer variables
// It finds the area of a rectangle given length and width
// It prints the length and width in ascending order
/*

int *lengthPtr = nullptr; // int pointer which will be set to point to length
int *widthPtr = nullptr; // int pointer which will be set to point to width
 This didnt work because nullptr was not in scope, so i removed it, not sure
 how it effected the program, but i guess it was just setting those variables to
 null.
*/

//Jonathan Branson - Lab9.1J_Branson.cpp
#include <iostream>

using namespace std;

int main()
{

	int length;	// holds length
	int width;	// holds width
	int area;	// holds area

	int *lengthptr;	// int pointer which will be set to point to length
	int *widthptr;	// int pointer which will be set to point to width


	cout << "Please input the length of the rectangle" << endl;
	cin >> length;

	cout << "Please input the width of the rectangle" << endl;
	cin >> width;

	lengthptr = &length;//getting length for pointer

	widthptr = &width;//getting width for pointer

	area = *lengthptr * *widthptr;//finding area with pointers

	cout << "The area is " << area << endl;

    //Determineing what was is larger or the same with the pointers
	if (*lengthptr > *widthptr)
		cout << "The length is greater than the width" << endl;

	else if (*lengthptr < *widthptr)
		cout << "The width is greater than the length" << endl;

	else
		cout << "The width and length are the same" << endl;

	return 0;
}
