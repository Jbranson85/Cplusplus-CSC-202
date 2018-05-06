/*
LAB7.4 #2

This program will let the user choose how many temperatures they would like to enter. It will
then ask the user to enter those temperatures. Finally it will output all temperatures entered,
the average temperature, the highest and lowest temperature that were input. Program will run until
user decides to quit. User can only enter a to of 50 temperatures.

Program includes validation for all user inputs (See userInputNumTemps and Validation for more details).
The validation is done by using ASCII values.

Jonathan Branson - Lab7.4-#2J_Branson.cpp

Adapted from code provided by Dr. Stange, Tony Gaddis(CSC book author), and Jonathan Branson(Validation)

*/

//Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#define MAX_TEMPS 50//Sets max array size

using namespace std;

typedef float temp_Array[MAX_TEMPS];//Sets type of array to float

//Prototype functions
void userInputNumTemps(int &);//Find number of temps includes validation
void fillArray(int, float[]);//Fill Array
void Validation(string, float &, bool &);//Validation
void final_Output(int,float[]);//final print out
void continue_Prog (char &);//user input to run program again
float avgTemp(int, float[]);//Finds average Temp
float highTemp(int, float[]);//Finds highest Temp
float lowTemp(int,float[]);//Finds lowest Temp

//Main Function
int main()
{
    char run_Again;//Variable used for continuing program
    int num_Temps;//Variable for array size/ number of temps
    temp_Array temps;//Array to hold temps

    //Main Loop to run program, until user is done
    do{

        userInputNumTemps(num_Temps);//Call function to find amount of temps, includes validation
        fillArray(num_Temps,temps);//Call function to fill array, works with Validation function
        final_Output(num_Temps,temps);//Call function to print final and all data collected
        continue_Prog(run_Again);//Call function to prompt user to run program again or quit

    }while(run_Again == 'Y');//End main loop

    return 0;
}

/*
    This function is used to allow the user to input the number of Temperatures that will be checked.
    The users input will then be ran through validation to make sure that the input is numbers only and
    is greater than 0 and less than 51. The validation is handled by reading input as a string, and the
    parsing the sting into chars. The chars are then converted to int to find the ASCII value of the
    character and checked by several statements. If input is valid it will then be converted back to int
    and returned as num_Temps. This function will run until valid data is entered. ***This is a working progress,
    still needs more testing, but seems to catch everything so far. If any error are found please inform me.
*/
void userInputNumTemps(int & num_Temps ){

    //Local Variables
    string input;//Variable to hold input
    bool invalid;//Variable for do while loop

    //Loop to look for valid data
    do{
        cout << "Please input number of Temperatures to checked (1-50).\n";
        getline(cin,input);//Get input
        invalid = true;//Set Variable if previous data was invalid

        //for loop that will loop and check every char one by one for invalid input data
        for(int x = 0; x <  input.length(); x++){

            //If statement to catch Invalid ASCII code/value, only 0-9
            if((input[x] <= 47) || (input[x] >= 58)){

                if (input[x] == 45){

                    cout << "\n\nINVALID INPUT -- POSITIVE NUMBERS ONLY\n\n";//Informs user of invalid input
                    invalid = false;//Set bool to false, make program loop again
                    break;//Breaks out of for loop as soon as it finds invalid char
                }

                else if (input[x] == 46){

                    cout << "\n\nINVALID INPUT -- WHOLE NUMBERS ONLY\n\n";//Informs user of invalid input
                    invalid = false;//Set bool to false, make program loop again
                    break;//Breaks out of for loop as soon as it finds invalid char
                }

                cout << "\n\nINVALID INPUT -- NUMBERS ONLY\n\n";//Informs user of invalid input
                invalid = false;//Set bool to false, make program loop again
                break;//Breaks out of for loop as soon as it finds invalid char
            }

        }//End of for loop

        //If passes int validation test
        if (invalid != false){

            num_Temps = atoi(input.c_str());//Convert String to int

            //If num_Temps is less then one or greater then 50
            if ((num_Temps < 1) || (num_Temps > MAX_TEMPS)) {

                cout << "\n\nINVALID INPUT -- Must be between 1 and 50.\n\n";//Informs user of invalid input
                invalid = false;//Set bool to false, make program loop again
            }
        }
    }while(invalid == false);//End of do while loop


}

/*
    This function is used to fill the array, it will work with the Validation function so that only valid
    input will be entered into the array.
*/
void fillArray(int num_Temps, float temps[]){

    //Local Variables
    string test_Input;
    bool temp_Invalid;
    float temp_Input;

    //For loop for total number of temps
    for(int x = 0; x < num_Temps; x++){

        //Do loop for validation
        do{
            cout << "\nInput a Temperature\n";
            getline(cin, test_Input);//Get input as string

            Validation(test_Input, temp_Input, temp_Invalid);//Call validation function

        }while(temp_Invalid == false);//End do while when temp_Invalid returns true from validation function

    temps[x] = temp_Input;//Inserts valid input into array
    }//End for loop


}

/*
    This function is used to validate user input for temperatures.It works a lot like the validation
    for the number of temperatures, but allows user to input negative numbers, and decimals. It still will
    only allow numbers only and will check for two negative signs or if the negative sign is not in front
    of the number. It will also check if more then one decimal place was entered. It works with ASCII values, will
    return to fill Array function but only fill array if input was invalid. ***This is a working progress,
    still needs more testing, but seems to catch everything so far. If any error are found please inform me.
*/
void Validation(string test_Input, float & temp_Input, bool & temp_Invalid){

    //Local Variables

    int check_Dec = 0, check_Neg = 0;//Used for counters for decimals and negative signs
    temp_Invalid = true;

     //for loop that will loop and check every char one by one for invalid input data
    for(int x = 0; x < test_Input.length(); x++){

        //If statement to catch Invalid ASCII code/value, only 0-9, decimal and, Negative are aloud to be used
        //Checks for decimal or negative first and wont check rest of the if statement if decimal or neg are used
            if( (test_Input[x] != 46 ) && (test_Input[x] != 45) && (test_Input[x] <= 47) || (test_Input[x] >= 58)){

                cout << "\n\nINVALID INPUT -- NUMBERS ONLY\n\n";//Informs user of invalid input
                temp_Invalid= false;//Set bool to false, make program loop again
                break;//Breaks out of for loop as soon as it finds invalid char
            }
            //Check for more then one decimal entered
            else if (test_Input[x] == 46){

                check_Dec++;//Add one if decimal is entered

                //If to catch if 2 or more decimals are entered
                if(check_Dec > 1){

                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    temp_Invalid = false;//Set bool to false, make program loop again
                    check_Dec = 0;//Reset counter
                    break;//Breaks out of for loop as soon as it finds invalid char
                }
            }
            //Checks for more then one negative sign entered
            else if (test_Input[x] == 45) {

                check_Neg++;//Add one if negative is entered

                 //If to catch if 2 or more negatives are entered
                if (check_Neg > 1){

                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    temp_Invalid = false;//Set bool to false, make program loop again
                    check_Neg = 0;//Reset counter
                    break;//Breaks out of for loop as soon as it finds invalid char
                }
            }
            //Checks if negative is not at the start of the number
            if ((test_Input[x] == 45) && (x > 0)){

                cout << "\nINVALID INPUT\n";//Informs user of invalid input
                temp_Invalid = false;//Set bool to false, make program loop again
                check_Neg = 0;//Reset counter
                break;//Breaks out of for loop as soon as it finds invalid char
            }

               if ((test_Input[0] == 48) && (!(test_Input[1] == 46)) && (test_Input[1] != 0)){


                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    temp_Invalid = false;//Set bool to false, make program loop again
                    check_Neg = 0;//Reset counter
                    check_Dec = 0;//Reset counter

                    break;
                }


        }//End of for loop

        //If passes int validation test
        if (temp_Invalid != false){

            temp_Input = strtof(test_Input.c_str(),0);//Converts string to float
            check_Neg = 0;//Reset counter
            check_Dec = 0;//Reset counter

        }

}

/*
    This function will find/ return the average of all the temperatures inputed.
*/
float avgTemp(int num_Temps, float temps[]){

    //Local variable
    float total = 0;

    //Loops through array
    for (int x = 0; x < num_Temps; x++){

        total =  total + temps[x];//Adds the temperatures together that are in the array
    }//End for loop

    return total/ float(num_Temps);//Returns the average temperature, cast int to float for num_Temps

}

/*
    This function will determine the highest temperature and return that value.
*/
float highTemp(int num_Temps, float temps[]){

    float high_Temp = temps[0];//Set high_Temp to first(zero) slot of the array

    //Loop to check array for the highest value
    for (int x = 0; x < num_Temps; x++){

            //If any temperatures higher then last will update new high_Temp
            if (temps[x] > high_Temp){

                high_Temp = temps[x];//Sets high_Temp to new value
            }
    }//End for loop

    return high_Temp;//Returns highest temperature
}

/*
    This function will determine the lowest temperature and return the value.
*/
float lowTemp(int num_Temps, float temps[]){

    float low_Temp = temps[0];//Set high_Temp to first(zero) slot of the array

    //Loop to check array for the lowest value
    for (int x = 0; x < num_Temps; x++){

        //If any temperatures lower then last will update new low_Temp
        if (temps[x] < low_Temp){

            low_Temp = temps[x];//Sets low_Temp to new value
        }
    }//End for loop

    return low_Temp;//Returns lowest temperature
}

/*
    This function will take all inputs and data collected and print them out. This
    function includes formating for the outputs.
*/
void final_Output(int num_Temps, float temps[]){

    //Chart titles and formating
    cout << "\n\n" << setw(10) << "Input #" << setw(25) << "Temperatures\n"
         << "-------------------------------------\n";

    //Creates a chart and outputs all the temperatures user inputed
    for (int x = 0; x < num_Temps; x++){

        cout << setw(7) << x+1 << setw(23) << temps[x] << '\n';
        cout << "-------------------------------------\n";
    }

    cout <<  "\n\n********************************************";

    //Output for average, calls the avgTemp function to get average of the temps, includes formatting 2 decimal points
    cout << "\n   Average of the " << num_Temps << " temperatures = "
         << fixed << showpoint << setprecision(2) << avgTemp(num_Temps,temps)
         << '\n';

    //Output for highest temperature, calls highTemp function to get highest temp, includes formatting 2 decimal points
    cout << "\n   Highest Temperature of the " << num_Temps << " = "
         << fixed << showpoint << setprecision(2) << highTemp(num_Temps, temps)
         << '\n';

    //Output for lowest temperature, calls lowTemp function to get lowest temp, includes formatting 2 decimal points
    cout << "\n   Lowest Temperature of the " << num_Temps << " = "
         << fixed << showpoint << setprecision(2) << lowTemp(num_Temps, temps)
         << '\n';

    cout <<  "********************************************\n\n";
}

/*
Function for validation of continue_Prog user input. This function will ask user if the want to run program
again. Function then checks the input and validates input. It only will take the first letter of what the
user inputs, and converts it to uppercase. If it is not valid it will run until its valid and will return
the char back to main for the do while loop to continue or close program.
*/
void continue_Prog(char & run_Again){

    run_Again = ' ';//Reset variable to empty to prepare for user input when program is ran more then once

    cout << "\nWould you like to run program again? (Y or N)\n";
    cin >> run_Again;//Gets user input
    cin.sync();//Used to only take first letter or Char of input
    run_Again = toupper(run_Again);//Formats it to uppercase

    //Loop used for validation of user input, checking for Y or N only, runs until correct input is entered
    while ((run_Again != 'Y') && (run_Again != 'N')){

        cout << "\nINVALID INPUT\n"
             << "\nWould you like to run program again (Y or N)\n";
             cin >> run_Again;//Get user input
             cin.sync();//Used to only take first letter or Char of input
             run_Again = toupper(run_Again);//Formats it to uppercase

    }//End of loop

    //If statement to clear screen if user want to run program again
    if (run_Again == 'Y'){

        system("cls");//clears screen
    }
}
