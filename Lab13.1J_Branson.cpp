// This program declares the Square class and uses member functions to find
// the perimeter and area of the square

// Jonathan Branson - Lab13.1J_Branson.cpp
// Adapted from code provided by Dr. Stange

#include <iostream>
using namespace std;

//Declaring Class called Square
class Square{

    //Member Variable
    float side;

    public:

        //Constructors and Destructor
        Square() {side = 1;}//Constructor 1 - default
        Square(float side_2) {side = side_2;}//Constructor 2 for box1
        ~Square() {;}//Destructor to reclaim memory space

        //Declaring prototypes for the functions
        void setSide(float);
        float findArea();
        float findPerimeter();
};

int main()
{
	Square box;	// box is defined as an object of the Square class
	float size;	// size contains the length of a side of the square
	Square box1(9);//give value of 9 to the constructor

    //Prompt for user input for length
	cout << "Enter the length of the side of the square? " << '\n';
	cin >> size;

	//Call setSide Function
	box.setSide(size);

	//Prints the area by calling findArea function
	cout << "\nThe area of the square = " << box.findArea() << '\n';

	//Print the perimeter by calling findPerimeter function
	cout << "The perimeter of the square = " << box.findPerimeter() << '\n';

	cout << "\nThe area the box1 = " << box1.findArea() << '\n'
         << "The perimeter of the box1 = " << box1.findPerimeter() << '\n';

	return 0;
}

// _______________________________________________________
//
// Implementation section	Member function implementation

//**************************************************
//  setSide
//
//  task:	 This procedure takes the length of a side and
//	         places it in the appropriate member data
//  data in: length of a side
//***************************************************

void Square::setSide(float length)
{
	side = length;
}

//**************************************************
//	findArea
//
//  task:	       This finds the area of a square
//  data in:       none (uses value of data member side)
//  data returned: area of square
//***************************************************

float Square::findArea()
{
	return side * side;
}

//**************************************************
//	findPerimeter
//
//  task:	       This finds the perimeter of a square
//  data in:       none (uses value of data member side)
//  data returned: perimeter of square
//***************************************************

float Square::findPerimeter()
{
	return 4 * side;
}
