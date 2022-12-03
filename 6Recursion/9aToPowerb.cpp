#include <iostream>
using namespace std;

int power(int a, int b)
{
    int ans;
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a;
    }

    b = b / 2;
    ans = power(a, b);
    return (ans * ans);
}

int main()
{
    int a, b;
    cout << "Enter number: ";
    cin >> a;
    cout << "Enter Power: ";
    cin >> b;

    if (b % 2 != 0)
    {
        b = b - 1;
        cout << (a * power(a, b));
    }
    else
    {
        cout << power(a, b);
    }

    return 0;
}