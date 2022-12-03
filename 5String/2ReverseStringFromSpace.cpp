#include <iostream>
#include <cstring>
using namespace std;

string reverse(string input, int s, int e)
{
    char temp;
    while (e >= s)
    {
        temp = input[s];
        input[s] = input[e];
        input[e] = temp;
        s++;
        e--;
    }
    return input;
}

int main()
{
    string input, output;
    int size, s, e, count = 0;
    cout << "Enter the string: ";
    getline(cin, input);
    size = input.length();

    s = 0;
    e = size;
    while (e >= s)
    {
        if (isspace(input[s]) || input[s] == '\0')
        {
            input = reverse(input, (s - count), (s - 1));
            count = 0;
        }
        else
        {
            count++;
        }
        s++;
    }
    cout << input;
    return 0;
}