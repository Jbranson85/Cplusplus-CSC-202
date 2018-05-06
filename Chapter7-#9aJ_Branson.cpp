/*
Jonathan Branson Chapter7-#9a

This program allow user to enter the amount of grades they want
to enter and the will prompt them to enter the grades. Grades
are placed in a array. THe grades are then averaged and array is
check for grades that are less then average.
*/

#include <iostream>

using namespace std;

//prototype for print function
void print(int, int*, int);

//Function for user input
void input(){

    //Variable for array size
    int num_Grades;

    cout << "Enter in the number of grades: ";
    cin >> num_Grades;

    //Array and total
    int grades[num_Grades], total = 0;

    //Loop to get grades and place in array
    for(int x = 0; x < num_Grades; x++){

        cout << "\nEnter in a grade: ";
        cin >> grades[x];

        //The running total used for average
        total += grades[x];

    }
    //Call print function
    print(num_Grades, grades, total);
}

//Function used to find average
double average(int total, int num_Grades){

    return static_cast<double>(total/ num_Grades);
}

//Print function
void print(int num_Grades, int grades[], int total){

     //Output calls average function
     cout << "\nThe average = " << average(total, num_Grades) << '\n';

    //Loop to find grades less then average
    for(int i = 0; i < num_Grades; i++){

        if (grades[i] < average(total, num_Grades)){

            cout << "\nGrade " << i+1 << " = " << grades[i] << " And is Less Then Average." << '\n';
        }
    }
}

int main()
{
    //Call function to start program
    input();
    return 0;
}
