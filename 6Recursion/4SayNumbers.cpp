#include <iostream>
#include <string>
using namespace std;

void divide(string chararr[], int number)
{
    int OnesPlace;
    if (number == 0)
    {
        return;
    }
    OnesPlace = number % 10;
    number = number / 10;
    divide(chararr, number);

    cout << chararr[OnesPlace] << " ";
}

int main()
{
    int number;
    int *numarr = new int[10]{0};
    string chararr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cout << "Enter Number: ";
    cin >> number;

    divide(chararr, number);
    return 0;
}