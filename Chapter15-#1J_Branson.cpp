#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee{

    private:
        string Name, hire_Date;
        int id_Num;

    public:
        Employee(){

            Name = "";
            hire_Date = "";
            id_Num = 0;
        }

        Employee(string name, string hire, int id){

            Name = name;
            hire_Date = hire;
            id_Num = id;
        }

        string getName(){

            return Name;
        }

        string getHire(){

            return hire_Date;
        }

        int getId(){

            return id_Num;
        }

        void setName(string name){

            Name = name;
        }
        void setHire(string hire){

            hire_Date = hire;
        }
        void setID(int id){

            id_Num = id;
        }
};

class ProductionWorker: public Employee
{
    private:
        int shift;
        double pay_Rate;

    public:

        ProductionWorker(string name, string hire, int id, int shf, double rate){

            setName(name);
            setHire(hire);
            setID(id);

            shift = shf;
            pay_Rate = rate;
        }
            int getShift(){
                return shift;
            }
            double getpay_Rate(){
                return pay_Rate;
            }

            void setShift(int Shift){

                shift = Shift;
            }

            void setpay_Rate(double rate){

                pay_Rate = rate;
            }
            void print();


};

int main()
{
    string name, hire_Date;
    int Id, shift;
    double pay_Rate;

   cout << "Enter Employee Name: ";
   cin >> name;

   cout << "Enter Hire Date (xx/xx/xxxx): ";
   cin >> hire_Date;

   cout << "Enter ID Number: ";
   cin >> Id;

   cout << "Enter in shift (1 = Day, 2 = Night): ";
   cin >> shift;

   cout << "Enter in Hourly Pay Rate: ";
   cin >> pay_Rate;

   ProductionWorker worker_1 (name, hire_Date, Id, shift, pay_Rate);
   worker_1.print();


    return 0;
}

void ProductionWorker::print(){

   cout << "\n\nEmployee Name: " << getName() << '\n'
        << "Hire Date: " << getHire() << '\n'
        << "Employee ID Number: " << getId()<< '\n';

   if(getShift() == 1){

        cout << "Shift: Day" << '\n';
   }
   else{

        cout << "Shift: Night" << '\n';
   }

   cout << "Hourly Pay Rate: $" << fixed << showpoint << setprecision(2)
        << getpay_Rate() << '\n';

}
