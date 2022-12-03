#include <iostream>
using namespace std;

int main()
{
    int arr1[5] = {1, 3, 4, 7, 9}, arr2[5], n = 5, last = 2, i = 0;
    while (i < n)
    {
        arr2[(i + last) % n] = arr1[i];
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << endl;
    }
    return 0;
}