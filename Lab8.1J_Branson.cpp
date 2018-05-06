// This program performs a linear search on a character array

//Jonathan Branson - Lab8.1J_Branson.cpp
//ADpated from code provided by Dr. Stange

#include <iostream>
using namespace std;

int searchList(int[], int, int); // function prototype



int main()
{
    int SIZE = 8;
	int number[SIZE] = {3,6,-19,5,5,0,-2,99};
	int found;
	int num_Input;

    do{


        cout << "Enter a number to add to the list"
             << '\n';
        cin >> number[SIZE];
        SIZE++;

    }while(SIZE < 12);

	cout << "\nEnter a number to search for:" << endl;
	cin >> num_Input;


	found = searchList(number, SIZE, num_Input);


	if (found == -1)
		cout << "\nThe number " << num_Input
		     << " was not found in the list" << endl;
	else
		cout << "\nThe number " << num_Input << " is in the " << found + 1
		     << " position of the list" << endl;

	return 0;
}

//*******************************************************************
//	searchList
//
//  task:	       This searches an array for a particular value
//  data in:	   List of values in an array, the number of
//	               elements in the array, and the value searched for
//	               in the array
//  data returned: Position in the array of the value or -1 if value
//	               not found
//
//*******************************************************************

int searchList(int List[], int numElems, int value)
{
	for (int count = 0; count <= numElems; count++)
	{
		if (List[count] == value)
			// each array entry is checked to see if it contains
			// the desired value.
			return count;
			// if the desired value is found, the array subscript
			// count is returned to indicate the location in the array
	}

	return -1;	// if the value is not found, -1 is returned
}
