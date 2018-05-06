/*
 This program will allow the user to enter there initial dollar and cents
 and will place them in their savings account. The user will then be prompted
 with a menu where they can withdraw, deposit, or check balance. The user can quit
 when they are done.

 Jonathan Branson - Lab13.5J_Branson.cpp
 Adapted from code provided by Dr.Stange

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Class declaration (header file)
class SavingsAccount{

    public:

        //Prototypes for functions
        void open(int, int);//for initial amount
        void deposit(int, int);//for deposit amount
        void withdraw(int, int);//for withdraw amount
        void print_Balance() const;//for print balance

    private:

        int dollars, cents;//Variables
        void normalize_Cents();//Prototype for function
};

int main()
{
    // use_1 is defined as an object of SavingsAccount class
    SavingsAccount user_1;

    //Variables
    int dollars, cents;
    char choice;//Used for menu

    //Output
    cout << '\n' << setw(50) << "------SAVINGS ACCOUNT------" << '\n';

    //Prompt for dollar amount initial
    cout << "\nEnter your initial dollar amount only" << '\n';
    cin >> dollars;

    //Prompt for cent amount initial
    cout << "\nEnter your initial cent amount only" << '\n';
    cin >> cents;

    //Call function open
    user_1.open(dollars, cents);

    //do until quit for menu
    do{

        cout << "\n**********MENU**********" << '\n';

        //Prompt to get user choice for menu
        cout << "Enter D for deposit" << '\n' << "Enter W for withdraw"
             << '\n' << "Enter C to check balance" << '\n'
             << "Enter Q to quit" << '\n';
        cin >> choice;

        //Change choice to upper
        choice = toupper(choice);

        //Switch for menu
        switch (choice){

            //deposit choice
            case 'D':

                cout << "\nEnter the dollar amount only that you are depositing" << '\n';
                cin >> dollars;

                cout << "Enter the cent amount only that you are depositing" << '\n';
                cin >> cents;

                //Call deposit function
                user_1.deposit(dollars, cents);
                break;

            //withdraw choice
            case 'W':

                cout << "\nEnter the dollar amount only that you are withdrawing" << '\n';
                cin >> dollars;

                cout << "Enter the cent amount only that you are withdrawing" << '\n';
                cin >> cents;

                //Call withdraw function
                user_1.withdraw(dollars, cents);
                break;

            //Print balance
            case 'C':

                user_1.print_Balance();
                break;

            //Quit
            case 'Q':

                exit(0);

            //Wrong input
            default:

                cout << "\n!!INVAID INPUT!!" << '\n';
                break;


        }
    }while((choice != 'D') || (choice != 'W') || (choice != 'C') ||
           (choice != 'Q'));

    return 0;
}

//Open function
void SavingsAccount::open(int dollar, int cent){

    dollars = dollar;
    cents = cent;
    normalize_Cents();//Call normalize_Cents function

}
//Deposit function
void SavingsAccount::deposit(int dollar, int cent){

    dollars += dollar;
    cents += cent;
    normalize_Cents();//Call normalize_Cents function

}
//Withdraw function
void SavingsAccount::withdraw(int dollar, int cent){

    dollars -= dollar;
    cents -= cent;
    normalize_Cents();//Call normalize_Cents function

}
/*Normalizing Cents function, this function is used adding a
dollar for every 100 cent or for taking away a dollar if no change
is available.
*/
void SavingsAccount::normalize_Cents(){

    //While loop for cents when over cents over 100
    while (cents >= 100){

        dollars += 1;
        cents -= 100;
    }
    //While loop for cents to take away dollar to get cents
    while (cents < 0){

        dollars -= 1;
        cents += 100;
    }
}
//Print Balance function
void SavingsAccount::print_Balance()const{

    //Prints balance with formating
    cout << "\nBalance ---> " << "Dollars = " << dollars << setw(10)
         << " Cents = " << cents << '\n';

}
