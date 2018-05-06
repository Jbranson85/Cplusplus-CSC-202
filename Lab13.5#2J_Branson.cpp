#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class SavingsAccount{

    public:

        SavingsAccount(int dollar = 0, int cent = 0);
        void deposit(int, int);
        void withdraw(int, int);
        void print_Balance() const;

    private:

        int dollars, cents;
        void normalize_Cents();

};

int main()
{


    int dollars, cents;

    cout << '\n' << setw(50) << "------SAVINGS ACCOUNT------" << '\n';

    cout << "\nEnter your initial dollar amount only" << '\n';
    cin >> dollars;

    cout << "\nEnter your initial cent amount only" << '\n';
    cin >> cents;

    SavingsAccount user_1 = SavingsAccount(dollars, cents);
    SavingsAccount user_2 = SavingsAccount();

    const int dollar = 10,  cent = 25;

    user_1.withdraw(dollar, cent);
    user_2.deposit(dollar, cent);

    cout << "\nWithdrew " << dollar << " Dollars and " << cent << " Cents to your other account."
         << '\n';

    user_1.print_Balance();
    user_2.print_Balance();

    return 0;
}

SavingsAccount::SavingsAccount(int dollar, int cent){

    dollars = dollar;
    cents = cent;
    normalize_Cents();

}

void SavingsAccount::deposit(int dollar, int cent){

    dollars += dollar;
    cents += cent;
    normalize_Cents();

}

void SavingsAccount::withdraw(int dollar, int cent){

    dollars -= dollar;
    cents -= cent;
    normalize_Cents();

}

void SavingsAccount::normalize_Cents(){

    while (cents >= 100){

        dollars += 1;
        cents -= 100;
    }
    while (cents < 0){

        dollars -= 1;
        cents += 100;
    }
}

void SavingsAccount::print_Balance()const{

    cout << "\nBalance ---> " << "Dollars = " << dollars << setw(10)
         << " Cents = " << cents << '\n';

}
