#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    cout << "Capacity: " << v.capacity() << endl;
    v.push_back(2);
    cout << "Capacity: " << v.capacity() << endl;
    v.push_back(3);
    cout << "Capacity: " << v.capacity() << endl;
    v.push_back(3);
    cout << "Capacity: " << v.capacity() << endl;
    v.push_back(3);
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    cout << "Element at 2: " << v.at(1) << endl;
    cout << v[2];
    v.pop_back();
    return 0;
}