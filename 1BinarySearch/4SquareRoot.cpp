#include <iostream>
using namespace std;

int main()
{
    long long int start, end, mid;
    double num, ans = -1, first;
    cout << "Enter number: ";
    cin >> num;
    start = 0;
    end = num;
    mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (mid * mid == num)
        {
            ans = mid;
            break;
        }
        else if (mid * mid > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            first = mid;
        }
        mid = start + (end - start) / 2;
    }
    if (ans == -1)
    {
        double factor = 1;
        int n = 7;
        for (int i = 0; i < n; i++)
        {
            factor = factor / 10;
            for (double j = first; j * j < num; j = j + factor)
            {
                ans = j;
            }
        }
        cout.precision(n);
        cout << ans;
    }
    else
    {
        cout << ans;
    }
    return 0;
}