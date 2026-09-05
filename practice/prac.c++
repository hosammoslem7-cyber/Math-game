#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include "my_input_lib.h"
#include <ctime>
#include <array>
using namespace std;

void FillMatrix(int (*arr)[3], int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      arr[i][j] = MyInputLip::random(1, 100);
    }
  }
}

int  Colsum(int (*arr)[3], int row, int col, int *arrsum)
{
  int sum=0;
  for ( int i = 0; i < row; i++)
  {
    sum += arr[i][col];
  }
 return sum;
}

void printEachCol(int (*arr)[3], int row, int col, int *arrsum)
{

  for (int i = 0; i < col; i++)
  {
   arrsum[i]= Colsum(arr, row, i, arrsum);
    // cout << "sum of col " << i + 1 << " is  " << << "\n";
  }
}

void print1D(int *arrsum, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "sum of col " << i + 1 << " is  " << arrsum[i] << "\n";
  }
}

void printMatrix(int (*arr)[3], int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << setw(3) << arr[i][j] << "   ";
    }
    cout << "\n";
  }
}

void swap(int &a,int&b)
{
    int temp=0;
    temp=a;
    a=b;
    b=temp;
}



int main()
{
  srand((unsigned)time(NULL));
  int arr[3][3];
  int arrsum[3];
  /*FillMatrix(arr, 3, 3);
  printMatrix(arr, 3, 3);
  printEachCol(arr, 3, 3, arrsum);
  print1D(arrsum, 3);*/
  int c=2,n=5;
swap(c,n);
cout<<c<<"\n";
cout<<n<<"\n";

}
