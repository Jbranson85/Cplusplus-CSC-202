// This program will read in a group of test scores (positive integers from 1 to 100)
// from the keyboard and then calculate and output the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.

//Jonathan Branson - Lab7.1-#1J_Branson.cpp

//Adapted from code provided by Prof. Stange and Walter B. Vaughan (to fix the while loop only line 39)

#include <iostream>
using namespace std;

typedef int GradeType[100];		// declares a new data type:
								// an integer array of 100 elements

float findAverage(const GradeType, int);	// finds average of all grades
int  findHighest(const GradeType, int);		// finds highest of all grades
int  findLowest(const GradeType, int);		// finds lowest of all grades

int main()
{
	GradeType grades;	// the array holding the grades.
	int numberOfGrades;	// the number of grades read.
	int pos;			// index to the array.
	float avgOfGrades;	// contains the average of the grades.
	int highestGrade;	// contains the highest grade.
	int lowestGrade;	// contains the lowest grade.

	// Read in the values into the array
	pos = 0;
	cout << "Please input a grade from 1 to 100, (or -99 to stop)" << endl;
	cin >> grades[pos];

    /*
        Couldn't get the code to work that is shown in the lab examples, so I
        had to add (++pos < 100) to get code to work. This was taken from
        Walter B. Vaughan code, line 39.
    */
	while ((grades[pos] != -99) && (++pos < 100))
	{
		cout << "Please input a grade from 1 to 100, (or -99 to stop)" << endl;
        cin >> grades[pos];//Adds grades to array

	}


	numberOfGrades = pos;	// Array size

	// call to the function to find average
	avgOfGrades = findAverage(grades, numberOfGrades);

	cout << endl << "The average of all the grades is " << avgOfGrades << endl;

	// Calls to the function that calculates highest grade
	highestGrade = findHighest(grades, numberOfGrades);

	cout << endl << "The highest grade is " << highestGrade << endl;

	// Calls to the function that calculates lowest grade
	lowestGrade = findLowest(grades, numberOfGrades);

	// Writes the lowest to the screen
    cout << '\n' << "The lowest grade is " << lowestGrade << '\n';

	return 0;
}

//********************************************************************************
// findAverage
//
// task:	      This function receives an array of integers and its size.
//	              It finds and returns the average of the numbers in the array
// data in:	      array of floating point numbers
// data returned: average of the numbers in the array
//
//********************************************************************************

float findAverage(const GradeType array, int size)
{
	float sum = 0;			// holds the sum of all the numbers

    //Loop to find sum
	for (int pos = 0; pos < size; pos++)
		sum = sum + array[pos];

	return (sum / size);	// returns the average
}

//****************************************************************************
// findHighest
//
// task:	      This function receives an array of integers and its size.
//	              It finds and returns the highest value of the numbers in
//                the array
// data in:	      array of floating point numbers
// data returned: highest value of the numbers in the array
//
//****************************************************************************

int	findHighest(const GradeType array, int size)
{
	//Sets max_Grade to first grade in array
	int max_Grade = array[0];

    //Loop to determine highest grade
	for (int x = 0; x < size; x++){

        //Catches high score the previous max
        if (array[x] > max_Grade){

            max_Grade = array[x];

        }
	}
	return max_Grade;//return highest grade
}

//****************************************************************************
// findLowest
//
// task:	      This function receives an array of integers and its size.
//	              It finds and returns the lowest value of the numbers in
//                the array
// data in:	      array of floating point numbers
// data returned: lowest value of the numbers in the array
//
//****************************************************************************

int	findLowest(const GradeType array, int size)
{
	//Set min_Grade to first grade in array
	int min_Grade = array[0];

    //Loop to determine lowest
	for (int x = 0; x < size; x++){

        //Catches low score the previous low
        if (array[x] < min_Grade){

            min_Grade = array[x];
        }
	}
	return min_Grade;//return lowest grade
}
