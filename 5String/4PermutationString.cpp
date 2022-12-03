#include <iostream>
#include <cstring>
using namespace std;

bool isper(int arr1[], int arr2[])
{
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            count++;
        }
    }
    if (count != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    string input1, input2;
    int arr1[26] = {}, arr2[26] = {}, size1, size2, index, s, e, count = 0;
    cout << "Enter the input 1: ";
    getline(cin, input1);
    size1 = input1.length();

    cout << "Enter the input 2: ";
    getline(cin, input2);
    size2 = input2.length();

    for (int i = 0; i < size2; i++)
    {
        index = input2[i] - 'a';
        arr2[index] = arr2[index] + 1;
    }

    s = 0;
    e = size2;
    for (int i = 0; i < (size1 - size2 + 1); i++)
    {
        for (int j = s; j < e; j++)
        {
            index = input1[j] - 'a';
            arr1[index] = arr1[index] + 1;
        }
        s++;
        e++;
        if (isper(arr1, arr2) == 1)
        {
            count++;
        }
    }
    if (count != 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}