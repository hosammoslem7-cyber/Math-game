#pragma once
#include <iostream>
using namespace std;
namespace My_Math_Lib
{
    int sum_with_recursion(int n)
    {
        if (n == 1)
            return 1;
        else
        {
            return n + sum_with_recursion(n - 1);
        }
    }
    int power_with_recursion(int Base, int power)
    {
        if (power == 0)
            return 1;
        else
        {
            return Base * power_with_recursion(Base, power - 1);
        }
    }
}