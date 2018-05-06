// This program demonstrates the use of dynamic variables

//Jonathan Branson -  Lab9.2J_Branson.cpp
//Some of the same problems here with nullptr and couldn't get program to work w/o name[pos]

#include <iostream>
using namespace std;

const int MAXNAME = 10;

int main()
{
	int pos;
	char *name;
	int *one;
	int *two;
	int *three;
	int result;

	//llocate the integer variable one here
    one =  new int;
	//allocate the integer variable two here
    two = new int;
	// allocate the integer variable three here
    three = new int;
	//the character array pointed to by name
	name = new char;

	cout << "Enter your last name with exactly 10 characters." << endl;
	cout << "If your name has < 10 characters, repeat last letter. " << endl
		 << "Blanks at the end do not count." << endl;

    //Placing into array..could not get it to work with out [pos]
	for (pos = 0; pos < MAXNAME; pos++)
		cin >>	*name;

	cout << "Hi ";

    //OutPut name from array...could not get to work without [pos]
	for (pos = 0; pos < MAXNAME; pos++)
		cout << &name;

	cout << endl << "Enter three integer numbers separated by blanks" << endl;

	cin >> *one >> *two >> *three;

	// echo print
	cout << "The three numbers are " << endl;

	cout << *one << " " << *two << " " << *three << '\n';

	result = *one + *two + *three;

	cout << "The sum of the three values is " << result << endl;

	//deallocate one, two, three and name
    delete one;
    delete two;
    delete  three;
    delete name;

	return 0;
}
