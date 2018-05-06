// This program demonstrates the use of characters and strings

//Jonathan Branson - Lab2.4J_Branson.cpp
//Adpated from code provided by Prof. Stange - stringchar.cpp

#include <iostream>
#include <string>
using namespace std;

// Definition of constants
const string FAVORITESODA = "Dr. Dolittle";	// use double quotes for strings
const char BESTRATING = 'A';				// use single quotes for characters

int main()
{
    //Defining variables that are not constants
	char rating = 'B';			        // 2nd highest product rating
	string favoriteSnack = "crackers";	// most preferred snack
	int numberOfPeople = 250;		    // the number of people in the survey
	int topChoiceTotal = 148;		    // the number of people who prefer the top choice


    //Print Statements
	cout << "The preferred soda is " << FAVORITESODA << endl;
	cout << "The preferred snack is " << favoriteSnack << endl;
	cout << "Out of " << numberOfPeople << " people "
		 << topChoiceTotal << " chose these items!" << endl;
	cout << "Each of these products were given a rating of " << BESTRATING <<
            " from our expert tasters" << endl;
	cout << "The other products were rated no higher than a " << rating
		 << endl;

	return 0;
}
