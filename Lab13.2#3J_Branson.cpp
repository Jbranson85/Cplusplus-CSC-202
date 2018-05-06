#include <iostream>
#include <cmath>
using namespace std;

// __________________________________________________________________
//
// This program declares a class for a circle that will have
// member functions that set the center, find the area, find
// the circumference and display these attributes.
// The program as written does not allow the user to input data, but
// rather has the radii and center coordinates of the circles
// (spheres in the program) initialized at definition or set by a function.

// class declaration section	(header file)

// Jonathan Branson- Lab13.2#3J_Branson.cpp
// Adpated from code provided by Dr. Stange

class Circles
{
    public:

        double findArea();
        double findCircumference();
        void printCircleStats();	// This outputs the radius and center of the circle.
        Circles();				    // Default constructor
        Circles(float r);			// Constructor
        Circles(float r, int x, int y); //Constructor
        Circles(int x, int y); //Constructor

    private:
        float radius;
        int	center_x;
        int	center_y;
};

const double PI = 3.14;

// Client section

int main()
{

	Circles sphere(8, 9, 10);//Float r , int x , int y

	sphere.printCircleStats();//Function to print circle states
	cout << "The area of the circle = " << sphere.findArea() << endl;
	cout << "The circumference of the circle = "
		 << sphere.findCircumference() << "\n\n";

    Circles sphere_1 = Circles(2);//giving sphere_1 radius of 2 and no x or y
    Circles sphere_2;//giving sphere_2 nothing so radius, x , and y will be default
    Circles sphere_3 = Circles(15,16);//Giving sphere_3 default radius and 15 x value and 16 y value

    //Call function to print Stats for sphere_1
    sphere_1.printCircleStats();
    //Print area and circumference for sphere_1 one using findArea and findCircumference functions
    cout << "The area of the circle = " << sphere_1.findArea() << '\n'
         << "The circumference of the circle = " << sphere_1.findCircumference()
         << "\n\n";
    //Call function to print stats for sphere_2
    sphere_2.printCircleStats();
    //Print area and circumference for sphere_2 one using findArea and findCircumference functions
    cout << "The area of the circle = " << sphere_2.findArea() << '\n'
         << "The circumference of the circle = " << sphere_2.findCircumference()
         << "\n\n";

    //Call function to print stats for sphere_3
    sphere_3.printCircleStats();
    //Print area and circumference for sphere_3 one using findArea and findCircumference functions
    cout << "The area of the circle = " << sphere_3.findArea() << '\n'
         << "The circumference of the circle = " << sphere_3.findCircumference()
         << "\n\n";


	return 0;
}

// __________________________________________________________________
//
// Implementation section	Member function implementation

// Implementation Function used for sphere_2
Circles::Circles(){

    radius = 1;
    center_x = 0;
    center_y = 0;

}

//Implementing Function used for sphere_1
Circles::Circles(float r){

    radius = r;
    center_x = 0;
    center_y = 0;
}
//Implementing the function for sphere
Circles::Circles(float r, int x, int y){

    radius = r;
    center_x = x;
    center_y = y;
}
//Implementing the function for sphere_3
Circles::Circles(int x, int y){

    radius = 1;
    center_x = x;
    center_y = y;
}

//Implementing the findArea member function
double Circles::findArea(){

    return PI * pow(radius,2);

}
//Implement the findCircumference member function
double Circles::findCircumference(){

    return PI * radius * 2;
}

void Circles::printCircleStats()
// This procedure prints out the radius and center coordinates of the circle
// object that calls it.
{
	cout << "The radius of the circle is " << radius << endl;
	cout << "The center of the circle is (" << center_x
		 << "," << center_y << ")" << endl;
}
