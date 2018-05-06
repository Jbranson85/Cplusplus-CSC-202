// This program reads floating point data from a data file and places those
// values into the private data member called values (a floating point array)
// of the FloatList class. Those values are then printed to the screen.
// The input is done by a member function called GetList. The output
// is done by a member function called PrintList. The amount of data read in
// is stored in the private data member called length. The member function
// GetList is called first so that length can be initialized to zero.

//Program included exercise 2 - 3

// Jonathan Branson - Lab13.3#2-3J_Branson.cpp
//Adapted from code provided by Dr.Stange and Tony Gaddis

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_LENGTH = 50;		// MAX_LENGTH contains the maximum length of our list
class FloatList					// Declares a class that contains an array of
								// floating point numbers
{
public:
	void getList(ifstream&);	// Member function that gets data from a file
	void printList() const;		// Member function that prints data from that file to the screen.
    void average();             // Member function for find average

	FloatList();				// constructor that sets length to 0.
	~FloatList();				// destructor

private:
	int length;					//	Holds the number of elements in the array
	float values[MAX_LENGTH];	//	The array of values

};

int main()
{
	ifstream tempData;	// Defines a data file

	// define an object called list of the class FloatList
	FloatList list;

	cout << fixed << showpoint;
	cout << setprecision(2);

	//open file
	tempData.open("temperatures.txt");

	//calls the getList function.
	list.getList(tempData);

	 //close file
    tempData.close();

	// calls the printList function.
    list.printList();

    list.average();

	return 0;
}
//constructor to set the private data member
FloatList::FloatList()
{
	//sets the private data member length to 0
	length = 0;
}
//getList function
void FloatList::getList(ifstream& infile){

    //Local Variable
    float temps;

    //loop used to read data from file and insert data into array of the class FloatList
    while(infile.good()){

        //Input data to temps variable
        infile >> temps;
        //Insert temps value into array and increase length by 1
        values[length++] = temps;
    }
}
//printList function
void FloatList::printList() const{

    //Loop to print array
    for (int x = 0; x < length; x++){

        cout << values[x] << '\n';
    }
}
//Find average Temp fucntion
void FloatList::average(){

    //Local Variable
    float total = 0;

    //Loop to add temperatures together
    for (int x = 0; x < length; x++){

        //Keep a running total for temperatures
        total += values[x];
    }

    //Output average
    cout << "\nThe average temperature = " << total / length << '\n';
}
//Implementation of the destructor
FloatList::~FloatList(){

    //Current does nothing but is needed
}
