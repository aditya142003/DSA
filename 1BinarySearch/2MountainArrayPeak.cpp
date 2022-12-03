#include <iostream>
using namespace std;

int main()
{
    int arr[9] = {2, 5, 10, 9, 8, 7, 5, 4, 3};
    int start, end, mid, ans = -1;
    start = 0;
    end = 9;
    mid = start + ((end - start) / 2);

    while (end >= start)
    {
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            ans = mid;
            break;
        }
        else if (arr[mid] < arr[mid - 1])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }
    cout << "Peak is: " << ans;
    return 0;
}