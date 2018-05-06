/*
This program will calculate the distance a object travels per foot fallin.
It will keep output the distance every second for 16 seconds total.

Jonathan Branson - Program 1 - Falling Objects

*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

    //Variables
    float gravity = 32;
    float time;
    float distance_Traveled;

    //Loop used to calculate the distance the object has fallen for every second
    for(int x = 1; x < 16; x++){

        //Formula
        distance_Traveled = .5 * gravity * pow(x,2);

        //Out for the distance traveled
        cout << fixed << showpoint << setprecision(2) << "The distance after "
             << x << " Seconds = " << distance_Traveled << " Feet" << "\n\n";
    }
    return 0;
}
