/*
This program ask the user to input the patient type (In or Out), the user will then be prompted
with a series of questions to determine the patient total bill. In patient will include amount of
days stayed and rate per day.

Valid data is working but not perfect, can still be broken with some input...working progress

Jonathan Branson - Chapter6-#15J_Branson.cpp

Adapted from code from Dr. Stange, Jonathan Branson, and Tony Gaddis.

*/

#include <iostream>
#include <string>
#include <cstdlib>//Used to change string to double- found in chapter 10
#include <stdalign.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//Prototype functions
void getChoice(string &);
void getContinueChoice(char &);
void testing_Input(string, double&);
double in_Patient (double, double, double, double);
double in_Patient (double, double);

int main()
{
    //Variables
    char continue_Choice = 'Y';
    char selection;
    string choice, test_Input;
    double daily_Rate, hospital_Service, med_Charges, days, test_Number;

    //Main Loop to make program run until user is done
    while(continue_Choice == 'Y'){

         //Menu
         cout << fixed << showpoint << setprecision(2);
         cout << "\nPatient's Current Status?\n\n"
         << "In = Inpatient\n"
         << "Out = Outpatient\n"
         << '\n';

        getChoice(choice); //Call function
        selection = choice[0];//Get the first char from choice used for switch statement

        //Switch statement for in or out patient
        switch (selection){

            //Inpatient
            case 'i':

                cout << "\n---------\n"
                     << "INPATIENT\n"
                     << "---------"
                     << '\n';
                     cin.ignore();//holds cin from taking previous input and running program, used b/c of getline()
                //Loop until valid data is entered for days
                do{

                    cout << "\nEnter Total Number of day Admitted.\n";
                    getline(cin,test_Input);//Input

                    testing_Input(test_Input,test_Number);//Call test number function

                    //Days from valid test number
                    days = test_Number;


                }while (test_Number < 0);//end loop

                 //Loop until valid data is entered for daily_Rate
                do{

                    cout << "\nEnter in the Daily Rate.\n";
                    getline(cin,test_Input);//Input

                    testing_Input(test_Input,test_Number);//Call test number function

                    //Daily_Rate from valid test number
                    daily_Rate = test_Number;

                }while (test_Number < 0);//End loop

                 //Loop until valid data is entered for med_Charges
                do{

                    cout << "\nEnter Medication Charges.\n";
                    getline(cin,test_Input);//Input

                    testing_Input(test_Input,test_Number);//Call test number function

                    //med_Charges from valid test number
                    med_Charges = test_Number;

                }while (test_Number < 0);//End loop

                 //Loop until valid data is entered for hospital_Service
                do{

                    //cout << fixed << showpoint << setprecision(2);
                    cout << "\nEnter Hospital Services Charges.\n";
                    getline(cin,test_Input);//Input

                    testing_Input(test_Input,test_Number);//Call test number function

                    //hospital_Service from valid test-Number
                    hospital_Service = test_Number;

                }while (test_Number < 0);//End loop

                //Print out total bill by using in_Patient function inside the cout
                cout << "\n\nTOTAL BILL = $" << in_Patient (days, daily_Rate, med_Charges, hospital_Service)
                     << "\n\n";
                break;

            //OutPatient
            case 'o':

                cout << "\n----------\n"
                     << "OUTPATIENT\n"
                     << "----------"
                     << '\n';
                     cin.ignore();//holds cin from taking last input and continuing program b/c of getline()

                //Loop until valid data is entered for hospital_Service
                do{

                    cout << "\nEnter Hospital Services Charges.\n";
                    getline(cin,test_Input);//Input

                    testing_Input(test_Input,test_Number);//Call test number function

                    //hospital_Service from valid test-Number
                    hospital_Service = test_Number;


                }while (test_Number < 0);//End loop

                do{

                    cout << "\nEnter Medication Charges.\n";
                    getline(cin,test_Input);//input
                    testing_Input(test_Input,test_Number);//Call test number function

                    //med_Charges from valid test-Number
                    med_Charges = test_Number;

                }while (test_Number < 0);//end loop

                //Print out total bill by using in_Patient function inside the cout
                cout << "\n\nTOTAL BILL = $" << in_Patient (med_Charges, hospital_Service)
                     << "\n\n";

                break;

            default:
                //Program failed
                cout << "ERROR";
                exit(0);
        }
        //Reseting continue_Choice to empty
        continue_Choice = ' ';
        getContinueChoice(continue_Choice);//Run ContinueChoice function to prompt user to continue
        //Switch for users choice to continue
        switch (continue_Choice){

            case 'Y':

                system("cls");
                break;

            case 'N':

                break;

            default:
                //Program fail
                cout << "\n!ERROR!\n";
                exit(0);
        }
    }

    return 0;
}
//Used for Menu choice
void getChoice(string & choice){

    cout << "\nEnter type of Patient (In or Out).\n";
    cin >> choice;

    //Loop to check each char in input
    for (int x = 0; x < choice.length(); x++){

            choice[x] = tolower(choice[x]);//Convert to lower case
        }
    //loop for if user enter invalid choice
    while ((choice != "out") && (choice != "in")){

        cout << "\nINVAID CHOICE\n"
             << "Enter type of Patient (In or Out).\n";
        cin >> choice;

        //Loop to check each char in input
        for (int x = 0; x < choice.length(); x++){

            choice[x] = tolower(choice[x]);
        }
    }
}
//Function for user wanting to continue program
void getContinueChoice(char & continue_Choice){

    cout << "\nWould You Like To Enter Another Patient?(Y or N)\n";
    cin >> continue_Choice;
    cin.sync();//Grabs just the first letter of the input
    continue_Choice = toupper(continue_Choice);//Change to uppercase

    while ((continue_Choice != 'Y') && (continue_Choice != 'N')){

        cout << "\nINVAID CHOICE\n"
             << "\nWould You Like To Enter Another Patient?(Y or N)\n";
        cin >> continue_Choice;
        cin.sync();//Grabs just the first letter of the input
        continue_Choice = toupper(continue_Choice);//Change to uppercase
    }

}
//Function to test Valid data
void testing_Input(string test_Input , double & test_Number ){

    //setting or resetting test_Number
    test_Number = 0;
    //Loop to check each char
    for (int x = 0; x < test_Input.length(); x++){
        //List of what incorrect data can be *Working progress still, is not perfect
        if((test_Input[x] <= 'z') && (test_Input[x] >= 'a') || (test_Input[x] <= 'Z') && (test_Input[x] >= 'A')
           || (test_Input[x] == ',') || (test_Input[x] == '-')){

            cout << "\nINVALID DATA\n";
            test_Number = -1;//to make loop run again
            break;
           }
    }
        if (test_Number > -1){

            test_Number = atof(test_Input.c_str());//Correct input changes entry from string to double

            if (test_Number == 0 ){

                cout << "\nINVALID DATA\n";//If input = 0, will force loop to run again
                test_Number = -1;
            }
        }
}
//Overload function for inpatient
double in_Patient(double days,double daily_Rate,double med_Charges,double hosital_Service){

    return (days * daily_Rate) + med_Charges + hosital_Service;
}
//Overload #2 function for out patient
double in_Patient(double med_Charges,double hosital_Service){

    return med_Charges + hosital_Service;
}
