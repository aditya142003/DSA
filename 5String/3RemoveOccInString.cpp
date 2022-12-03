#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string input, part;
    int size, s, e;
    cout << "Enter the string: ";
    getline(cin, input);
    cout << "Enter the part to delete: ";
    getline(cin, part);
    size = input.length();

    s = 0;
    e = size;
    while (e != 0 && input.find(part) < e)
    {
        input.erase(input.find(part), part.length());
    }
    cout << input;
    return 0;
}