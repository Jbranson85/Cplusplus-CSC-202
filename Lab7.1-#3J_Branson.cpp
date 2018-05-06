// This program will read in a group of test scores (positive integers from 1 to 100)
// from the keyboard and then calculate and output the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.

//Jonathan Branson - Lab7.1-#1J_Branson.cpp

//Adapted from code provided by Prof. Stange and Walter B. Vaughan (to fix the while loop only)

#include <iostream>
#include <fstream>
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
	int pos = 0;			// index to the array.
	float avgOfGrades;	// contains the average of the grades.
	int highestGrade;	// contains the highest grade.
	int lowestGrade;	// contains the lowest grade.

	ifstream dataIn; // defines an input stream for a data file

	dataIn.open("gradfile.txt");// This opens the file.

    /*Had to added (pos < 100) and dataIn.good() to get code to work,
      I could not get what the lab showed to work, line 37, line 39
      and line 40 are used from Walter B. Vaughan's code.
    */
	while ((dataIn.good()) && (pos < 100))//while runs until collects all data and pos < 100
	{
		dataIn >> grades[pos];//Inputs data into the array from file
		pos++;//Moves to next slot in the array
	}

	numberOfGrades = pos;	// Fill blank with appropriate identifier

	 //Closes files
    dataIn.close();

	// call to the function to find average
	avgOfGrades = findAverage(grades, numberOfGrades);

	cout << endl << "The average of all the grades is " << avgOfGrades << endl;

	// Fill in the call to the function that calculates highest grade
	highestGrade = findHighest(grades, numberOfGrades);

	cout << endl << "The highest grade is " << highestGrade << endl;

	// Fill in the call to the function that calculates lowest grade
	lowestGrade = findLowest(grades, numberOfGrades);

	// Fill in code to write the lowest to the screen
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

	for (int x = 0; x < size; x++){

        if (array[x] > max_Grade){

            max_Grade = array[x];

        }
	}
	return max_Grade;
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

	for (int x = 0; x < size; x++){

        if (array[x] < min_Grade){

            min_Grade = array[x];
        }
	}
	return min_Grade;
}
