#include <iostream>

using namespace std;

int main()
{

    int num_Rows = 2, num_Cols = 3;

    int first[num_Rows][num_Cols] = {16 , 18, 23,
                                     54, 91, 11};
    int second[num_Rows][num_Cols] = {24, 52, 77,
                                      16, 19, 59};
    int result[num_Rows][num_Cols];

    for (int x = 0; x < num_Rows; x++){

        for(int i = 0; i < num_Cols; i++){


            result[x][i] = first[x][i] + second[x][i];
        }
    }

      for (int z = 0; z < num_Rows; z++){

        cout << '\n';

        for(int q = 0; q < num_Cols; q++){

            cout << " " << result[z][q];
        }
    }


    return 0;
}
