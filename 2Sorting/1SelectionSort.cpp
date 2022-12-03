#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n], min, j;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array after sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        j = i + 1;
        min = j;
        while (j < n)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            j++;
        }
        if (arr[i] > arr[min])
        {
            swap(arr[i], arr[min]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}