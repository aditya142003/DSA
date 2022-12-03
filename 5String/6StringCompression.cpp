#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string input, output;
    int arr[26] = {}, index;
    int size, s, e, tens, ones;
    cout << "Enter the string: ";
    getline(cin, input);
    size = input.length();

    s = 0;
    e = size;
    while (e > s)
    {
        if (input[s] >= 'a' && input[s] <= 'z')
        {
            index = input[s] - 'a';
            arr[index]++;
        }
        if (input[s] >= 'A' && input[s] <= 'Z')
        {
            index = input[s] - 'A';
            arr[index]++;
        }
        s++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        else
        {
            output.push_back(i + 'a');

            if (arr[i] > 9)
            {
                tens = arr[i] / 10;
                ones = arr[i] % 10;
                output.push_back(tens + 48);
                output.push_back(ones + 48);
            }
            else
            {
                output.push_back(arr[i] + 48);
            }
        }
    }
    cout << output;
    return 0;
}