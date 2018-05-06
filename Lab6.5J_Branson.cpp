#include <iostream>
#include <iomanip>
using namespace std;

// This program will demonstrate the scope rules.

//Jonathan Branson - Lab6.5J_Branson.cpp

const double PI = 3.14;
const double RATE = 0.25;

void findArea(float, float&);
void findCircumference(float, float&);

int main()
{
	cout << fixed << showpoint << setprecision(2);
	float radius = 12;

	cout << " Main function outer block" << endl;
	cout << " Radius, PI, RATE are active here" << endl << endl;
    //First inner block
	{
		float area;

		cout << "Main function first inner block" << endl;
		cout << "Area, Radius PI, Rate are active here" << endl << endl;

		//Call find area function
		findArea(radius, area);

		cout << "The radius = " << radius << endl;
		cout << "The area = " << area << endl << endl;
	}
    //Second inner block
	{
		float radius = 10;
		float circumference;

		cout << "Main function second inner block" << endl;
		cout << "Radius, Circumference PI, Rate are active here" << endl << endl;

		//Call find Circumference function
		findCircumference(radius,circumference);

		cout << "The radius = " << radius << endl;
		cout << "The circumference = " << circumference << endl << endl;
	}

	cout << "Main function after all the calls" << endl;
	cout << "Radius , PI, Rate are active here" << endl << endl;

	return 0;
}

//	*********************************************************************
//	findArea
//
//	task:	  This function finds the area of a circle given its radius
//	data in:  radius of a circle
//	data out: answer (which alters the corresponding actual parameter)
//
//	********************************************************************

void findArea(float rad, float& answer)
{
	cout << "AREA FUNCTION" << endl << endl;
	cout << "Rad, answer, PI, Rate are active here" << endl << endl;

	//Calculation of Area
	answer = (rad * rad) * PI;
}

//	******************************************************************************
//	findCircumference
//
//	task:	  This function finds the circumference of a circle given its radius
//	data in:  radius of a circle
//	data out: distance (which alters the corresponding actual parameter)
//
//	*****************************************************************************

void findCircumference(float length, float& distance)
{
	cout << "CIRCUMFERENCE FUNCTION" << endl << endl;
	cout << "Length, distance, PI, Rate are active here" << endl << endl;

	//Calculation for circumference
	distance = PI * length * 2;
}
