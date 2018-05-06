/*
Lab8.4
This program will first ask how many numbers they would like to enter. The user will then
be prompted to enter those number, then be ask to choose a number to check to see if it is in
the array. The numbers the entered will be put into a array, then sorted for lowest to highest.
The program will then look for the number chosen to check array for, if found the number and
position in the array will be output. If not found user will be informed that number isn't in
the list. The happens after array is sorted. Output will show array before and after sort, size
of the array, number to check array for and if it is or is not found, and the mean value of
the list. **Program includes validation for all user inputs (See userInputArrayNums and Validation
for more details). The validation is done by using ASCII values.

Jonathan Branson -- Lab8.4J_Branson.cpp

Adapted from code provided by Dr. Stange (Lab8.4,Lab 8.1,etc) and previously written code
by Jonathan Branson (Mostly Validation codes and continue function).

*/

//Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#define MAX_NUMS 50//Sets max array size

using namespace std;

typedef float array_Nums[MAX_NUMS];//Sets type of array to float

//Prototype functions
void userInputArrayNums(int &);//Find amount of numbers that will be entered includes validation
void fillArray(int, float[]);//Fill Array
void Validation(string, float &, bool &);//Validation
void check_Array(float &);//User input for checking if number is in array
void sort_Array(int, float[]);//Sorts array
void final_Output(int,float[],float);//final print out
void continue_Prog (char &);//user input to run program again
int search_Array(int, float[], float);//Search array
float mean_Value(int, float[]);//Find mean for the array

using namespace std;

//Main function
int main()
{
    char run_Again;//Variable used for continuing program
    int array_Size;//Variable for array size
    float check_ArrayNum;//Variable for determining if number is in array
    array_Nums numbers;//Array to hold numbers

    //Loop to run program till user wants to quit
    do{
        userInputArrayNums(array_Size);//Call function to find amount of numbers, includes validation
        fillArray(array_Size,numbers);//Call function to fill array, works with Validation function
        check_Array(check_ArrayNum);//Call function to get user input for checking if number is in array, works with Validation function
        final_Output(array_Size,numbers, check_ArrayNum);//Call function to print final and all data collected
        continue_Prog(run_Again);//Call function to prompt user to run program again or quit

    }while(run_Again == 'Y');//End main loop



    return 0;
}

/*
    This function is used to allow the user to input the number for the size of the array.
    The users input will then be ran through validation to make sure that the input is numbers only and
    is greater than 0 and less than 51. The validation is handled by reading input as a string, and the
    parsing the sting into chars. The chars are checked with their ASCII value of the
    character and checked by several statements. If input is valid it will then be converted  to int
    and returned as array_Size. This function will run until valid data is entered. ***This is a working progress,
    still needs more testing, but seems to catch everything so far. If any error are found please inform me.
*/
void userInputArrayNums(int & array_Size){

    //Local Variables
    string input;//Variable to hold input
    bool invalid;//Variable for do while loop

    //Loop to look for valid data
    do{

        cout << "Please input Array size (1-50).\n";
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

            array_Size = atoi(input.c_str());//Convert String to int

            //If num_Temps is less then one or greater then 50
            if ((array_Size < 1) || (array_Size > MAX_NUMS)) {

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
void fillArray(int array_Size, float numbers[]){

    //Local Variables
    string test_Input;
    bool num_Invalid;
    float num_Input;

    //For loop for total number of temps
    for(int x = 0; x < array_Size; x++){

        //Do loop for validation
        do{
            cout << "\nInput a Number\n";
            getline(cin, test_Input);//Get input as string

            Validation(test_Input, num_Input, num_Invalid);//Call validation function

        }while(num_Invalid == false);//End do while when num_Invalid returns true from validation function

    numbers[x] = num_Input;//Inserts valid input into array
    }//End for loop
}

/*
    This function is used to validate user input for array size.It works a lot like the validation
    for the number of temperatures, but allows user to input negative numbers, and decimals. It still will
    only allow numbers only and will check for two negative signs or if the negative sign is not in front
    of the number. It will also check if more then one decimal place was entered. It check if zero has been
    entered but not followed by a decimal. It works with ASCII values, will return to fill Array function but
    only fill array if input was invalid. ***This is a working progress,still needs more testing, but seems
    to catch everything so far. If any error are found please inform me.
*/
void Validation(string test_Input, float & num_Input, bool & num_Invalid){

    //Local Variables
    int check_Dec = 0, check_Neg = 0;//Used for counters for decimals and negative signs
    num_Invalid = true;

     //for loop that will loop and check every char one by one for invalid input data
    for(int x = 0; x < test_Input.length(); x++){

        //If statement to catch Invalid ASCII code/value, only 0-9, decimal and, Negative are aloud to be used
        //Checks for decimal or negative first and wont check rest of the if statement if decimal or neg are used
            if( (test_Input[x] != 46 ) && (test_Input[x] != 45) && (test_Input[x] <= 47) || (test_Input[x] >= 58)){

                cout << "\n\nINVALID INPUT -- NUMBERS ONLY\n\n";//Informs user of invalid input
                num_Invalid = false;//Set bool to false, make program loop again
                break;//Breaks out of for loop as soon as it finds invalid char
            }
            //Check for more then one decimal entered
            else if (test_Input[x] == 46){

                check_Dec++;//Add one if decimal is entered

                //If to catch if 2 or more decimals are entered
                if(check_Dec > 1){

                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    num_Invalid = false;//Set bool to false, make program loop again
                    check_Dec = 0;//Reset counter
                    check_Neg = 0;//Reset counter
                    break;//Breaks out of for loop as soon as it finds invalid char
                }
            }
            //Checks for more then one negative sign entered
            else if (test_Input[x] == 45) {

                check_Neg++;//Add one if negative is entered

                 //If to catch if 2 or more negatives are entered
                if (check_Neg > 1){

                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    num_Invalid = false;//Set bool to false, make program loop again
                    check_Neg = 0;//Reset counter
                    check_Dec = 0;//Reset counter
                    break;//Breaks out of for loop as soon as it finds invalid char
                }
            }
            //Checks if negative is not at the start of the number
            if ((test_Input[x] == 45) && (x > 0)){

                cout << "\nINVALID INPUT\n";//Informs user of invalid input
                num_Invalid = false;//Set bool to false, make program loop again
                check_Neg = 0;//Reset counter
                break;//Breaks out of for loop as soon as it finds invalid char
            }
            //Check for invalid ex. 00235, 05663, etc.
            if ((test_Input[0] == 48) && (!(test_Input[1] == 46)) && (test_Input[1] != 0)){


                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    num_Invalid = false;//Set bool to false, make program loop again
                    check_Neg = 0;//Reset counter
                    check_Dec = 0;//Reset counter
                    break;
                }
        }//End of for loop

        //If passes int validation test
        if (num_Invalid != false){

            num_Input = strtof(test_Input.c_str(),0);//Converts string to float
            check_Neg = 0;//Reset counter
            check_Dec = 0;//Reset counter

        }
}

/*
    This function handles sorting the array from lowest to highest. Called from final output function.
    This code was taken/ used from Lab 8.3 and is a bubble sort.
*/
void sort_Array(int array_Size, float numbers[]){

    //Local variables
    bool switch_Array;//Used for do while loop
    float temp_Var;//Hold temp number during switch
    int bottom = array_Size - 1;

    do{

        switch_Array = false;//set bool to false

        //Loop that handles the reversing of the array
        for(int x = 0; x < bottom; x++){

            if(numbers[x] > numbers[x+1]){

                //Makes the switch happen
                temp_Var = numbers[x];
                numbers[x] = numbers[x + 1];
                numbers[x+1] = temp_Var;

                switch_Array = true;//indicates switch happened
            }
        }
        bottom--;//reduces bottom by one each time through loop

    }while (switch_Array != false);//end loop once it has gone through entire array
}

/*
    This function will get users input for check array for a certain number. It also run through
    the validation function, once valid choice is made it returns users input to main.
*/
void check_Array(float & chec_ArrayNum){

    //Local Variables
    string test_Input;
    bool num_Invalid;
    float num_Input;

        //Do loop for validation
        do{
            cout << "\nInput number to check array for\n";
            getline(cin, test_Input);//Get input as string

            Validation(test_Input, num_Input, num_Invalid);//Call validation function

        }while(num_Invalid == false);//End do while when num_Invalid returns true from validation function

    chec_ArrayNum = num_Input;//Initializing variable that will be returned

}

/*
    This function is used to search the sorted array for, the number the user is checking. Returns
     x if found, and -1 if not found. Is called from final print out function.
*/
int search_Array(int array_Size, float numbers[], float check_ArrayNum){

    //Loop got check array
    for (int x = 0; x <= array_Size; x++){

        //If statement for if the number is found
        if(numbers[x] == check_ArrayNum){

            return x;//return the x value
        }
    }
    return -1;//Return -1 if not found in the array
}

/*
    This function will find the mean value of the array.
*/
float mean_Value(int array_Size, float numbers[]){

    //Local variable
    float sum = 0;

    //Loop through array
    for(int x = 0; x < array_Size; x++){

        sum += numbers[x];//adds each entry to sum to get a total
    }
    return sum/float(array_Size);//Return the mean value which  is (sum/array size)
}

/*
    This function will take all inputs and data collected and prints them out. This
    function includes formating for the outputs. This function will call/use the sort
    function, mean, and search functions.
*/
void final_Output(int array_Size, float numbers[], float check_ArrayNum){


    //Chart titles and formating
    cout << "\n\n" << setw(27) << "Unsorted Array" << '\n';
    cout << "-------------------------------------\n";
    cout <<  setw(18) << "Array Position" << setw(15) << "Number(s)\n"
         << "-------------------------------------\n";

    //Creates a chart and outputs all the numbers user inputed
    for (int x = 0; x < array_Size; x++){

        cout << setw(10) << x+1 << "(" << x << ")" << setw(15) << numbers[x] << '\n';
        cout << "-------------------------------------\n";
    }

    sort_Array(array_Size,numbers);//Calling sort function

     //Chart titles and formating
    cout << "\n\n" << setw(25) << "Sorted Array" << '\n';
    cout << "-------------------------------------\n";
    cout <<  setw(18) << "Array Position" << setw(15) << "Number(s)\n"
         << "-------------------------------------\n";

    //Creates a chart and outputs all the numbers user inputed
    for (int x = 0; x < array_Size; x++){

        cout << setw(10) << x+1 << "(" << x << ")" << setw(15) << numbers[x] << '\n';
        cout << "-------------------------------------\n";
    }

    cout << "\n*******************************************" << '\n';
    cout << "The size of the array == " << array_Size << '\n';//Prints array size

    //if number user is checking for is not found in the array
    if((search_Array(array_Size, numbers, check_ArrayNum)) == -1){

        cout << "The number " << check_ArrayNum << " is not a choice in the list."
             << '\n';
    }
    //The number was found in the array
    else{

         cout << "The number " << check_ArrayNum << " is in the list and is in the \n"
              << search_Array(array_Size, numbers, check_ArrayNum) + 1 << " position of the list."
              << '\n';
    }

    //If is for whole numbers means, else for decimal means, to determine format
    if ((mean_Value(array_Size,numbers) == (int)mean_Value(array_Size,numbers))){

        cout << fixed << noshowpoint << setprecision(0) << "The mean of the list = " << mean_Value(array_Size,numbers) << '\n';
    }
    else{

         cout << fixed << showpoint << setprecision(2) <<"The mean of the list = " << mean_Value(array_Size,numbers) << '\n';
    }

    cout << "*******************************************" << '\n';
}

/*
    Function for validation of continue_Prog user input. This function will ask user if the want to run program
    again. Function then checks the input and validates input. It only will take the first letter of what the
    user inputs, and converts it to uppercase. If it is not valid it will run until its valid and will return
    the char back to main for the do while loop to continue or close program.
*/
void continue_Prog(char & run_Again){

    run_Again = ' ';//Reset variable to empty to prepare for user input when program is ran more then once

    cout << "\n\nWould you like to run program again? (Y or N)\n";
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

