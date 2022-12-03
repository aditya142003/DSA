#include <iostream>
using namespace std;

int sum(int *arr, int size)
{
    if (size == 0)
        return 0;

    else if (size == 1)
        return arr[0];

    return arr[0] + sum(arr + 1, size - 1);
    ;
}

int main()
{
    int size = 1, ans;
    int *arr = new int[size]{8};
    ans = sum(arr, size);
    cout << "Sum is: " << ans;
    return 0;
}