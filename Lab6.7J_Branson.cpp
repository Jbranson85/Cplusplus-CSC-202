#include <iostream>
#include <iomanip>
using namespace std;

// This program will input American money and convert it to foreign currency

//Jonathan Branson = Lab6.7J_Branson.cpp
//Adpated from code provided by Dr. Stange

// Prototypes of the functions
void convertMulti(float dollars, float& euros, float& pesos);
void convertMulti(float dollars, float& euros, float& pesos, float& yen);
float convertToYen(float dollars);
float convertToEuros(float dollars);
float convertToPesos(float dollars);

int main()
{
	float dollars;
	float euros;
	float pesos;
	float yen;

	cout << fixed << showpoint << setprecision(2);

	cout << "Please input the amount of American Dollars you want converted "
		 << endl;
	cout << "to euros and pesos" << endl;
	cin >> dollars;

    //Calls function for multi convert
	convertMulti(dollars, euros, pesos);

	cout << "Euros = " << euros << '\n'
         << "Pesos = " << pesos << '\n';

	cout << "\nPlease input the amount of American Dollars you want converted\n";
	cout << "to euros, pesos and yen" << endl;
	cin >> dollars;

    //Calls function for multi convert to include yen
	convertMulti(dollars, euros, pesos, yen);
	cout << "Euros = " << euros << '\n'
         << "Pesos = " << pesos << '\n'
         << "Yen = "   <<  yen  << '\n';

	cout << "\nPlease input the amount of American Dollars you want converted\n";
	cout << "to yen" << endl;
	cin >> dollars;

    //Calls function in out put, getting results from the return
    cout << "Yen = " << convertToYen(dollars) << '\n';

	cout << "\nPlease input the amount of American Dollars you want converted\n";
	cout << " to euros" << endl;
	cin >> dollars;

    //Calls function in out put, getting results from the return
	cout << "Euros = " << convertToEuros(dollars) << '\n';

	cout << "\nPlease input the amount of American Dollars you want converted\n";
	cout << " to pesos " << endl;
	cin >> dollars;

    //Calls function in out put, getting results from the return
	cout << "\nPesos = " << convertToPesos(dollars) << '\n';

	return 0;
}

// All of the functions are stubs that just serve to test the functions
// Replace with code that will cause the functions to execute properly

//	**************************************************************************
//	convertMulti
//
//	task:	  This function takes a dollar value and converts it to euros
//	          and pesos
//	data in:  dollars
//	data out: euros and pesos
//
//	*************************************************************************

void convertMulti(float dollars, float& euros, float& pesos)
{
	cout << "The function convertMulti with dollars, euros and pesos "
		 << endl << " was called with " << dollars << " dollars" << endl << endl;

    euros = dollars * 1.06;
    pesos = dollars * 9.73;
}

//	************************************************************************
//	convertMulti
//
//	task:	  This function takes a dollar value and converts it to euros
//	          pesos and yen
//	data in:  dollars
//	data out: euros pesos yen
//
//	***********************************************************************

void convertMulti(float dollars, float& euros, float& pesos, float& yen)
{
	cout << "The function convertMulti with dollars, euros, pesos and yen"
		 << endl << " was called with " << dollars << " dollars" << endl << endl;

    euros = dollars * 1.06;
    pesos = dollars * 9.73;
    yen = dollars * 124.35;
}

//	****************************************************************************
//	convertToYen
//
//	task:	       This function takes a dollar value and converts it to yen
//	data in:	   dollars
//	data returned: yen
//
//	***************************************************************************

float convertToYen(float dollars)
{
	cout << "The function convertToYen was called with " << dollars << " dollars"
		 << endl << endl;



	return dollars * 124.35;
}

//	****************************************************************************
//	convertToEuros
//
//	task:	       This function takes a dollar value and converts it to euros
//	data in:	   dollars
//	data returned: euros
//
//	****************************************************************************

float convertToEuros(float dollars)
{
	cout << "The function convertToEuros was called with " << dollars
		 << " dollars" << endl << endl;

	return dollars * 1.06;
}

//	*****************************************************************************
//	convertToPesos
//
//	task:	       This function takes a dollar value and converts it to pesos
//	data in:	   dollars
//	data returned: pesos
//
//	****************************************************************************

float convertToPesos(float dollars)
{
	cout << "The function convertToPesos was called with " << dollars
		 << " dollars" << endl;

	return dollars * 9.73;
}
