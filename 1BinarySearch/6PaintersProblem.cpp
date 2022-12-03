#include <iostream>
using namespace std;

int *input()
{
    int *arr;
    int a[4] = {1, 2, 3, 4};
    arr = a;
    return arr;
}

int ispossible(int *arr, int mid, int painters)
{
    int timesum = 0, req = 1;
    for (int i = 0; i < 4; i++)
    {
        if (timesum + arr[i] <= mid)
        {
            timesum = timesum + arr[i];
        }
        else
        {
            req++;
            timesum = arr[i];
            if (req > painters)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int *arr = input();
    int start = 0, end, mid, painters = 2, ans = -1;
    for (int i = 0; i < 4; i++)
    {
        end = end + arr[i];
    }
    mid = start + (end - start) / 2;

    while (end >= start)
    {
        if (ispossible(arr, mid, painters) == 1)
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

    cout << "Minimum time is: " << ans;
    return 0;
}