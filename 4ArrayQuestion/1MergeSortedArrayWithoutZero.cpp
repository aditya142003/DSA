#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr1[6] = {1, 2, 3, 0, 0, 0}, arr2[3] = {1, 1, 6}, n = 5, m = 2;
    for (int i = 0; i < 6; i++)
    {
        if (arr2[m] >= arr1[n] && n >= 0 && m >= 0)
        {
            arr1[n] = arr2[m];
        }
        else
        {
            break;
        }
        n--;
        m--;
    }
    sort(arr1, arr1 + 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr1[i];
    }

    return 0;
}