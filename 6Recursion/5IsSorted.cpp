#include <iostream>
using namespace std;

bool IsSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return IsSorted(arr + 1, size - 1);
    }
}

int main()
{
    int size = 5;
    int *arr = new int[size]{1, 2, 3, 3, 5};
    if (IsSorted(arr, size - 1))
    {
        cout << "Sorted";
    }
    else
    {
        cout << "Not Sorted";
    }
    return 0;
}