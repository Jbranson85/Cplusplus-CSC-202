// This program displays a hot beverage menu and prompts the user to
// make a selection. A switch statement determines which item the user
// has chosen. A do-while loop repeats until the user selects item E
// from the menu.

//Jonathan Branson - Lab5.2J_Branson.cpp
//Adapted from code provided by Dr.Stange

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Variables
	int number;
	float cost;
	char beverage;
	bool validBeverage;

    //Formating
	cout << fixed << showpoint << setprecision(2);

	do
	{
	    //Output to create menu
		cout << endl << endl;
		cout << "Hot Beverage Menu" << endl << endl;
		cout << "A: Coffee	$1.00" << endl;
		cout << "B: Tea	$ .75" << endl;
		cout << "C: Hot Chocolate	$1.25" << endl;
		cout << "D: Cappuccino	$2.50" << endl << endl << endl;

		cout << "Enter the beverage A,B,C, or D you desire" << endl;
		cout << "Enter E to exit the program" << endl << endl;
		//Input
		cin >> beverage;

		//Switch statement to display drink choice that user choose
		switch (beverage)

		{
			case 'a':
			    cout << "Coffee\n";
			    validBeverage = true;
			    break;

			case 'A':
			    cout << "Coffee\n";
			    validBeverage = true;
			    break;

			case 'b':
			    cout << "Tea\n";
			    validBeverage = true;
			    break;

			case 'B':
			    cout << "Tea\n";
			    validBeverage = true;
			    break;

			case 'c':
			    cout << "Hot Chocolate\n";
			    validBeverage = true;
			    break;

			case 'C':
			    cout << "Hot Chocolate\n";
			    validBeverage = true;
			    break;

			case 'd':
			    cout << "Cappuccino\n";
			    validBeverage = true;
			    break;

			case 'D':
			    cout << "Cappuccino\n";
			    validBeverage = true;
			    break;
            //For quit or wrong choice entered
			default: validBeverage = false;
		}
        //If beverage ordered then ask amount user wants
		if (validBeverage == true)
		{
			cout << "How many cups would you like?" << endl;
			cin >> number;
		}

		//Switch for beverage cost and prints total cost
		switch(beverage)
		{
			case 'a':
			    cost = number * 1.0;
			    cout << "\nThe total cost is $" << cost << endl;
				break;

			case 'A':
			    cost = number * 1.0;
				cout << "\nThe total cost is $" << cost << endl;
				break;

            case 'b':
                cost = number * .75;
				cout << "\nThe total cost is $" << cost << endl;
				break;

            case 'B':
                cost = number * .75;
				cout << "\nThe total cost is $" << cost << endl;
				break;

            case 'c':
                cost = number * 1.25;
				cout << "\nThe total cost is $" << cost << endl;
				break;

            case 'C':
                cost = number * 1.25;
				cout << "\nThe total cost is $" << cost << endl;
				break;

            case 'd':
                cost = number * 2.50;
				cout << "\nThe total cost is $" << cost << endl;
				break;

            case 'D':
                cost = number * 2.50;
				cout << "\nThe total cost is $" << cost << endl;
				break;

			case 'e':
			    cout << "\nPlease come again" << endl;
				break;

			case 'E':
			    cout << "\nPlease come again" << endl;
				break;
            //Wrong choice entered
			default:
                 cout << "Invalid choice" << endl;
				 cout << "Try again please" << endl;
		}

	}
	//End do while loop
	while((beverage != 'e') && (beverage != 'E'));

    return 0;
}
