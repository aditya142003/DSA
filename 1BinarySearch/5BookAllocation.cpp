#include <iostream>
using namespace std;

bool ispossible(int mid)
{
    int person = 1, sum = 0, n = 3, a[4] = {5, 17, 100, 11};
    for (int i = 0; i < 4; i++)
    {
        if (sum + a[i] <= mid)
        {
            sum = sum + a[i];
        }
        else
        {
            person++;
            if (person > n || a[i] > mid)
            {
                sum = a[i];
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int a[4] = {5, 17, 100, 11}, n = 3, start, end, mid, ans = -1;
    start = 0;
    for (int i = 0; i < 4; i++)
    {
        end = end + a[i];
    }
    mid = start + (end - start) / 2;

    while (end >= start)
    {
        if (ispossible(mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    cout << ans;
    return 0;
}