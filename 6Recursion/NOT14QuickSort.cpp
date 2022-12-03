#include <iostream>
using namespace std;

void sort(int *arr, int s, int e)
{
    if (s >= e)
    {
        swap(arr[0], arr[e]);
        return;
    }
    int num = arr[0];
    if (arr[s] < num)
    {
        s++;
    }
    if (arr[e] > num)
    {
        e--;
    }
    swap(arr[s], arr[e]);
    sort(arr++, s, e);
    return;
}

int main()
{
    int size = 6;
    int *arr = new int[size]{11, 25, 22, 7, 9, 12};

    sort(arr, 0, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}