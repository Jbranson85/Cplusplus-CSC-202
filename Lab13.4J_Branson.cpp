#include <iostream>
#include <fstream>
using namespace std;

// This program declares a class called Inventory that has itemnNumber (which
// contains the id number of a product) and numOfItem (which contains the
// quantity on hand of the corresponding product) as private data members.
// The program will read these values from a file and store them in an
// array of objects (of type Inventory). It will then print these values
// to the screen.

// Jonathan Branson - Lab13.4J_Branson.cpp
// Adapted from code provided by Dr. Stange and Tony Gaddius

// Example: Given the following data file:
//		986 8
//		432 24
//
// This program reads these values into an array of objects and prints the
// following:
//		Item number 986 has 8 items in stock
//		Item number 432 has 24 items in stock

const int NUMOFPROD = 10;		// This holds the number of products a store sells

class Inventory
{
public:
	void getId(int item);		// This puts item in the private data member
								// itemNumber of the object that calls it.

	void getAmount(int num);	// This puts num in the private data member
								// numOfItem of the object that calls it.

	void display();				// This prints to the screen
								// the value of itemNumber and numOfItem of the
								// object that calls it.

private:
	int	itemNumber;				// This is an id number of the product
	int	numOfItem;				// This is the number of items in stock

};

int main()
{
	ifstream infile;	// Input file to read values into array
	infile.open("Inventory.dat");

	//defines an array of objects of class Inventory
	Inventory products[NUMOFPROD];

	int pos = 0;	// loop counter
	int id;		// variable holding the id number
	int total;	// variable holding the total for each id number

	// Loop read inventory number and number of  each items from a file into the array of objects
	//End when pos is greater the NUMOFPROD
	while((infile.good()) && (pos < NUMOFPROD)){

        //Get input from file id then total
        infile >> id >> total;

        //Places id number and total amount into array of objects by using the functions getId and getAmount
        products[pos].getId(id);
        products[pos].getAmount(total);

        //Increase counter by 1, need to end loop once all data is read in
        pos++;

	}

	// Print out the values (itemNumber and numOfItem) for each object in the array
	for( int x = 0; x < pos; x++){

        //Call display function
        products[x].display();
	}

    //Close file
    infile.close();

	return 0;
}

// The member function for getId
void Inventory::getId(int item){

    itemNumber = item;
}
//The member function for getAmount
void Inventory:: getAmount(int num){

    numOfItem = num;
}
//The member function for display
void Inventory::display(){

    //Output for each item, includes item number and amount of each item
    cout << "Item #" << itemNumber << " has " << numOfItem << " items in stock" << '\n';
}
