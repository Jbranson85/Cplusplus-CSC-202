/*
Jonathan Branson- Chapter7-#JBranson.cpp

This program will move through a array and find the min number and the
max number in the array and print the output.

*/

#include <iostream>

using namespace std;
//Function to find max number in array
void find_Max(double& max_Num, double slope[]){

    //set max number to first slot in array
    max_Num = slope[0];

    //Loop to find the highest number
    for (int x = 0; x < 9; x++){

        //Check if number is higher then the last
        if (max_Num < slope[x]){

            max_Num = slope[x];
        }
    }
}
//Function to find min number in array
void find_Min(double& min_Num, double slope[]){

    //set min number to the first number in the array
    min_Num = slope[0];

    //Loop to find the lowest number
    for (int x = 0; x < 9; x++){

        //Check if number is lower then the last
        if (min_Num > slope[x]){

            min_Num = slope[x];
        }
    }
}
//Function to print output
void print(double max_Num, double min_Num){

    cout << "\nThe maximum slope found = " << max_Num
         << "\nThe minimum slope found = " << min_Num
         << '\n';

}
//Main program
int main()
{
    //Variable for program, including array
   double max_Num, min_Num, slope[9] = {17.24, 25.63, 5.94,
    33.92, 3.71, 32.84, 35.93, 18.24, 6.92};

    //Calling function for max, min and print
    find_Max(max_Num, slope);
    find_Min(min_Num, slope);
    print(max_Num, min_Num);

    return 0;
}
