#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
using namespace std;
namespace MyInputLip
{

    int Readnumber()
    {
        cout << "Enter number\n";
        int number;
        cin >> number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid one:" << endl;
            cin >> number;
        }
        return number;
    }
    void read_num_to_vector(vector<int> &vNumber)
    {
        char choice = 'y';
        do
        {
            cout << "Enter your Number\n";
            int number;
            cin >> number;
            vNumber.push_back(number);

            cout << " Do you want enter  another Number?\n";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }

    int random(int from, int to)
    {
        int randnum = rand() % (to - from + 1) + from;
        return randnum;
    }

}