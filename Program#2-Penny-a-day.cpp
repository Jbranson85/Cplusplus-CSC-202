/*
This program will calculate a penny a day and double it each day for
64 days. It will output the vlue for every day and include the total amount
for all 64 day.

Jonathan Branson - Program #2 - penny-a-day
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Variables
    float amount = 0.01;
    float total;
    int millon;

    //Loop to calculate the total and total for each day
    for( int x = 1; x < 65; x++){

        //Catches input for day one
        if (x == 1){

            amount = amount;
            cout << "The amount the king must by the Begger for "
                 << x << " day = " << fixed << showpoint
                 << setprecision(2) << amount << '\n';
        }
        //Calculates the amount for each day after the first
        else{
            amount = (amount *2);
            cout << "The amount the king must by the Begger for "
                 << x << " day = " << fixed << showpoint
                 << setprecision(2) << amount << '\n';
        }
        //Calculates and keeps track of the total
        total += amount;

        if(( total > 999999) && (total < 1500000)){

            //cout << "\nYou hit a Million\n";
            millon = x;
        }


    }
    //Outputs the total amount owned by the king after 64 days
    cout << "\n\nThe total amount the king must by the begger = "
          << fixed << showpoint << setprecision(2) << total << "\n";

    cout << "Begger became a millionaire on day " << millon + 1 << "\n\n";

    return 0;
}
