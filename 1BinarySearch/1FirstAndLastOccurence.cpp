#include <iostream>
using namespace std;

int *input(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

int first(int* arr, int n, int search)
{
    int start, end, mid, ans = -1;
    start = 0;
    end = n - 1;
    mid = start + ((end - start) / 2);
    while (end >= start)
    {
        if (arr[mid] == search)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > search)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}

int last(int* arr, int n, int search)
{
    int start, end, mid, ans = -1;
    start = 0;
    end = n - 1;
    mid = start + ((end - start) / 2);
    while (end >= start)
    {
        if (arr[mid] == search)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > search)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int *arr = input(n);
    int search = 7;
    cout << "First occurence is: " << first(arr, n, search) << endl;
    cout << "Last occurence is: " << last(arr, n, search) << endl;
    return 0;
}