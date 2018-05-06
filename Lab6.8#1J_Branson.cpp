#include <iostream>
#include <string>
#include <cstdlib>
#include <stdalign.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void check_Choice(int&);
int main()
{


    int choice;
    double miles, kilometers;
    char continue_Choice = 'Y';


        check_Choice(choice);





    switch (choice){

            case 1:

                cout << "Please input the miles to be converted.\n";

                break;

            case 2:

                break;

            case 3:

                break;

            default:

            cout << "\nERROR\n";

        }




    return 0;
}

void check_Choice(int & choice){

    string choice_Check;

    do{

        cout << "\nPlease Input\n"
             << "1 = Convert miles to kilometers\n"
             << "2 = Convert kilometers to miles\n"
             << "3 = Quit\n"
             << '\n';

        getline(cin,choice_Check);

        for (int x = 0; x < choice_Check.length(); x++){

            if((choice_Check[x] <= 'z') && (choice_Check[x] >= 'a') || (choice_Check[x] <= 'Z') && (choice_Check[x] >= 'A')
            || (choice_Check[x] == ',') || (choice_Check[x] == '-')){

                cout << "\nINVALID DATA\n";
                choice = -1;
                break;
            }
        }
            if ((choice_Check == "1") || (choice_Check == "2") || (choice_Check == "3")){

                choice = atof(choice_Check.c_str());
            }
            else {
                cout << "\nINVALID DATA\n";
                choice = -1;
            }

    } while ((choice != 1) && (choice != 2) && (choice != 3));


}
