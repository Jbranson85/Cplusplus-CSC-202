#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//Function prototypes
void program_Details();
void determineSpeed(float, float, float&);

int main()
{
    //Main Variables used
    float miles, hours, miles_Per_Hour;
    char continue_1 = 'Y';
    int choice;

    //Main loop for whole program
    while (continue_1 == 'Y'){

        cout << "\n\t\t\t  *****AVERAGE SPEED TEST*****\n\n";

        //do while loop for correct choice
        do{
                cout << "Menu - Enter Choice 1-3\n"
                     << "-----------------------\n"
                     << "1-Check Miles\n"
                     << "2-Program Details\n"
                     << "3-Exit\n\n";

                cin >> choice;

                switch(choice){

                    case 1:

                        choice;
                        break;

                    case 2:

                        //Call function for program_Details
                        program_Details();
                        break;

                    case 3:
                        //Ends program
                        exit(0);
                        break;

                    default:
                        //Check for wrong choice entered
                        cout << "\n\nInvaded Entry You entered " << choice <<  " Enter only number 1 - 3\n\n";
                        cin >> choice;
                        cout << '\n';
                }

        }while(choice != 1);//end of do while loop must enter 1 to exit loop

        //Set format for output
        cout << setprecision(2) << fixed;

        //User input for miles
        cout << "\nPlease input the total miles traveled.\n";
        cin >> miles;

        //Checks for cin fail...so only numbers can be entered for miles
        while (cin.fail()){

                cin.clear();//clears the cin
                cin.ignore();//Ignores input
                cout << "\nINVAID INPUT."
                     << "\nPlease input the total miles traveled. (Numbers only)\n";
                cin >> miles;
         }

        //User input for hours
        cout << "\nPlease input total hours traveled.\n";
        cin >> hours;

        //Check for cin fail...so only numbers can be entered for hours
        while (cin.fail()){

                cin.clear();//clears the cin
                cin.ignore();//Ignores input
                cout << "\nINVAID INPUT."
                     << "\nPlease input the total hours traveled. (Numbers only)\n";
                cin >> hours;
         }

        //Calls function determineSpeed
        determineSpeed(miles, hours, miles_Per_Hour);

        //Final output to show miles per hour
        cout << "\nThe average speed you were traveling = " << miles_Per_Hour << " miles per hour."
             << "\n\n";

        //Setting variable to empty to prepare user choice to run program again
        continue_1 = ' ';
        while ((continue_1 != 'Y') && (continue_1 != 'N')){

                //User input to run program again
                cout << "\n\nWould you like to check another trip? (Y/N)\n";
                cin >> continue_1;

                if (continue_1 == 'Y'){

                    //Clear Console screen
                    system("cls");
                }
            }

    }//End of while loop for main program


    return 0;
}

//Function for program details
void program_Details(){

    cout << "\n------------------------------------------------------------"
         << "\n* This program will calculate the average speed traveled   *\n"
         << "* by giving the program total miles traveled and the total *\n"
         << "* hours it took.                                           *\n"
         << "------------------------------------------------------------"
         << "\n\n";


}
//Function for determining speed
void determineSpeed(float miles, float hours, float& miles_per_hour){

    //Calculation for miles per hour
    miles_per_hour = miles / hours;

}
