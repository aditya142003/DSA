#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> v, int size)
{
    int s = 0;
    int e = size - 1;
    while (s < e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}

int main()
{
    int n, m, a, b, carry = 0, sum, ans, size;
    vector<int> v;
    cout << "Enter length both array: " << endl;
    cin >> n >> m;
    int arr1[n], arr2[m];
    a = n - 1;
    b = m - 1;
    cout << "Enter 1st Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter 2nd Array: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    while (a >= 0 && b >= 0)
    {
        sum = arr1[a] + arr2[b] + carry;
        carry = sum / 10;
        ans = sum % 10;
        v.push_back(ans);
        a--;
        b--;
    }
    if (a > b)
    {
        while (a >= 0)
        {
            sum = arr1[a] + carry;
            carry = sum / 10;
            ans = sum % 10;
            v.push_back(ans);
            a--;
        }
    }
    else if (a < b)
    {
        while (b >= 0)
        {
            sum = arr2[b] + carry;
            carry = sum / 10;
            ans = sum % 10;
            v.push_back(ans);
            b--;
        }
    }
    if (carry != 0)
    {
        ans = carry;
        v.push_back(ans);
    }

    size = v.size();
    v = reverse(v, size);

    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}