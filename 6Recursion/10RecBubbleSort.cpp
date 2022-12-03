#include <iostream>
using namespace std;

void sort(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    
    //step after every recursion
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    sort(arr, size - 1);
    return;
}

int main()
{
    int size = 5;
    int *arr = new int[size]{5 ,4, 3, 2, 1};
    sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    return 0;
}