#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{
    int length1 = mid - start + 1;
    int length2 = end - mid;

    int* first = new int[length1];
    int* second = new int[length2];

    int mainArrIndex = start;
    for (int i = 0; i < length1; i++)
    {
        first[i] = arr[mainArrIndex++];
    }
    for (int i = 0; i < length2; i++)
    {
        second[i] = arr[mainArrIndex++];
    }

    // merge
    mainArrIndex = start;
    int index1 = 0;
    int index2 = 0;

    while (index1 < length1 && index2 < length2)
    {
        if (first[index1] > second[index2])
        {
            arr[mainArrIndex++] = second[index2++];
        }
        else
        {
            arr[mainArrIndex++] = first[index1++];
        }  
    }
    while(index1 < length1){
        arr[mainArrIndex++] = first[index1++];
    }
    while(index2 < length2){
        arr[mainArrIndex++] = second[index2++];
    }
    return;
}

void sort(int *arr, int start, int end)
{
    int mid;
    if (start >= end)
    {
        return;
    }
    // For left
    mid = start + (end - start) / 2;
    sort(arr, start, mid);
    // For right
    sort(arr, mid + 1, end);

    // merge
    merge(arr, start, mid, end);
}

int main()
{
    int size = 6;
    int *arr = new int[size]{5, 2, 4, 3, 1, 8};
    sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}