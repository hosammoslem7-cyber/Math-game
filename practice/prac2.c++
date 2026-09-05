#include <iostream>
#include "my_input_lib.h"
#include <ctime>
using namespace std;

void FillMatrix(int (*arr)[3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = MyInputLip::random(1, 10);
        }
    }
}

void printMatr(int (*arr)[3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // printf("%0*d  ", 2, arr[i][j]);
            cout << arr[i][j] << "   ";
        }
        cout << "\n";
    }
}

void print1D(int (*arr1)[3], int row, int col, int *arrrow)
{
    for (int i = 0; i < col; i++)
    {
        printf("%0*d  ", 2, arrrow[i]);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    

}