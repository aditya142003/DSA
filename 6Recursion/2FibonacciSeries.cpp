#include <iostream>
using namespace std;

int series(int n)
{
    int ans;
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    ans = series(n - 1) + series(n - 2);
    return ans;
}

int main()
{
    int n;
    cout << "Enter length of series: ";
    cin >> n;
    cout << series(n);
    return 0;
}