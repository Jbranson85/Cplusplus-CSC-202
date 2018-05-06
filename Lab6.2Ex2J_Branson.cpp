// This program will allow the user to input from the keyboard
// whether the last word to the following proverb should be party or country:
// "Now is the time for all good men to come to the aid of their ___"
// Inputting a 1 will use the word party. Any other number will use the word country.

// PLACE YOUR NAME HERE

#include <iostream>
#include <string>
using namespace std;

// Fill in the prototype of the function writeProverb.
void writeProverb(int wordCode);

int main()
{
	int wordCode;

	cout << "Given the phrase:" << endl;
	cout << "Now is the time for all good men to come to the aid of their ___"
		 << endl;

	cout << "Input a 1 if you want the sentence to be finished with party"
		 << endl;
	cout << "Input any 2 for the word country" << endl;

	cout << "Please input your choice now" << endl;
	cin >> wordCode;
	cout << endl;

	do{

         switch(wordCode){

            case 1:
                wordCode;
                break;
            case 2:
                wordCode;
                break;
            default:
                cout << "\nI'm sorry but that is an incorrect choice; Please input a 1 or 2.\n";
                cin >> wordCode;
                break;
        }

	}while((wordCode < 1) || (wordCode > 2));

    writeProverb(wordCode);

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

void writeProverb(int wordCode)
{
	if (wordCode == 1){

        cout << "\nNow is the time for all good men to come the aid of their party.\n";
	}
    else if (wordCode == 2){

        cout << "\nNow is the time for all good men to come the aid of their country.\n";
    }


}
