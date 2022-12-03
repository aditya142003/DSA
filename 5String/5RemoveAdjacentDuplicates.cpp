#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string input;
    int size, s, e;
    cout << "Enter the string: ";
    getline(cin, input);

    s = 0;
    while (input[s] != '\0')
    {
        if (input[s] == input[s + 1])
        {
            input.erase(s, 2);
            s = -1;
        }
        s++;
    }
    cout << input;
    return 0;
}