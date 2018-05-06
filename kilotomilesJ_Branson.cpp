//This program ask user for number of kilometers and converts it to miles
//Jonathan Branson- kilotomilesJ_Branson.cpp

#include <iostream>

using namespace std;

int main()
{
    float numberOfKilo;
    float totalMiles;

    //Print out asking user for kilometers to be converted
    cout << "Enter in the number of Kilometers you would like to convert to Miles." << endl;

    //Stores user input to numberOfKilo
    cin >> numberOfKilo;

    //Equation to find total number of Miles
    totalMiles = numberOfKilo * 0.621371;

    //Outputs answer for the conversion
    cout << "\nThat is a total of " << totalMiles << " Miles" << endl;

    return 0;
}
