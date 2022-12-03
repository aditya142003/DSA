#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n], min, temp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array after sorting:" << endl;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {

                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}