#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {4, 5, 7, 10, 1, 2, 3};
    int start, end, mid;
    start = 0;
    end = 6;
    mid = start + ((end - start) / 2);

    while (end > start)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + ((end - start) / 2);
    }
    cout << "Pivot is: " << start;
    return 0;
}