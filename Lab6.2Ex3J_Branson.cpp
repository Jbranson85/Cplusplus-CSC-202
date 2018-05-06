// This program will allow the user to input from the keyboard
// whether the last word to the following proverb should be party or country:
// "Now is the time for all good men to come to the aid of their ___"
// Inputting a 1 will use the word party. Any other number will use the word country.

// PLACE YOUR NAME HERE

#include <iostream>
#include <string>
using namespace std;

// Fill in the prototype of the function writeProverb.
void writeProverb(string word);

int main()
{
    string word;

	cout << "Given the phrase:" << endl;
	cout << "Now is the time for all good men to come to the aid of their ___."
		 << endl;

	cout << "Input a the if you want the sentence to be finished the proverb with."
		 << endl;

	cout << "Please input your choice now" << endl;
	cin >> word;
	cout << endl;

    writeProverb(word);

	return 0;
}

//	******************************************************************************
//	writeProverb
//
//	task:	  This function prints a proverb. The function takes a number
//	          from the call. If that number is a 1 it prints "Now is the time
//	          for all good men to come to the aid of their party."
//	          Otherwise, it prints "Now is the time for all good men
//	          to come to the aid of their country."
//	data in:  code for ending word of proverb (integer)
//	data out: no actual parameter altered
//
//	*****************************************************************************

void writeProverb(string word)
{

	cout << "\nNow is the time for all good men to come to the aid of their " << word
         << ".\n";


}
