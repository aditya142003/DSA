#include <iostream>
#include <string>
using namespace std;

void reverse(string &name, int s, int e)
{

    if (e < s)
    {
        return;
    }
    else
    {
        swap(name[s], name[e]);
        reverse(name, s + 1, e - 1);
    }
}

int main()
{
    int size;
    string name = "abcde";
    size = name.size();
    int s = 0, e = size - 1;
    reverse(name, s, e);
    cout << name;
    return 0;
}