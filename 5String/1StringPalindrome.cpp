// Favourite


#include <iostream>
#include <string>
using namespace std;

string ValidChar(string input, int size)
{
    int s, e;
    string valid;
    s = 0;
    e = size;
    while (e > s)
    {
        if ((input[s] >= 'a' && input[s] <= 'z') || (input[s] >= 'A' && input[s] <= 'Z') || (input[s] >= '0' && input[s] <= '9'))
        {
            if (input[s] >= 'A' && input[s] <= 'Z')
            {
                valid.push_back((input[s] - 'A' + 'a'));
            }
            else
            {
                valid.push_back(input[s]);
            }
        }
        s++;
    }
    return valid;
}

string Reverse(string input, int size)
{
    int s, e;
    char temp;
    s = 0;
    e = size - 1;
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

bool CheckPalin(string input, string output, int size)
{
    int s, e, count = 0;
    s = 0;
    e = size;
    while (e > s)
    {
        if (input[s] != output[s])
        {
            count++;
        }
        s++;
    }
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string input, output;
    int size;
    cout << "Enter the string: ";
    getline(cin, input);
    size = input.length();

    input = ValidChar(input, size);
    size = input.length();
    output = Reverse(input, size);

    if (CheckPalin(input, output, size))
    {
        cout << "Yes it is a Palindrome";
    }
    else
    {
        cout << "No it is not a Palindrome";
    }
    return 0;
}