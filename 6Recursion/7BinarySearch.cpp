#include <iostream>
using namespace std;

int search(int *arr, int start, int end, int mid, int toFind)
{
    if (start > end)
    {
        return -1;
    }
    if (arr[mid] == toFind)
    {
        return mid;
    }
    else if (arr[mid] < toFind)
    {
        start = mid + 1;
        mid = start + (end - start) / 2;
        return search(arr, start, end, mid, toFind);
    }
    else
    {
        end = mid - 1;
        mid = start + (end - start) / 2;
        return search(arr, start, end, mid, toFind);
    }
}

int main()
{
    int size = 10, toFind = 10;
    int start = 0, end = size - 1, mid;
    mid = start + (end - start) / 2;
    mid = start + (end - start) / 2;
    mid = start + (end - start) / 2;
    int *arr = new int[size]{1, 2, 5, 7, 8, 9, 9, 10, 12, 15};
    cout << "Found at index: "<<search(arr, start, end, mid, toFind);
    return 0;
}