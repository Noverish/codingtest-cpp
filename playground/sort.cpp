#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print_vector(vector<T> &arr) {
    for(auto it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {1,9,8,2,3,7,6,4,5};
    vector<string> arr2 = {"apple", "chocolate", "banana", "eco", "daemon"};

    cout << "Sort int vector ascending order: ";
    sort(arr1.begin(), arr1.end());
    print_vector(arr1);

    cout << "Sort int vector decending order: ";
    sort(arr1.rbegin(), arr1.rend());
    print_vector(arr1);

    cout << "Sort string vector ascending order: ";
    sort(arr2.begin(), arr2.end());
    print_vector(arr2);

    cout << "Sort string vector decending order: ";
    sort(arr2.rbegin(), arr2.rend());
    print_vector(arr2);

    cout << "Sort string vector custom order: ";
    sort(arr2.begin(), arr2.end(), [](const string &a, const string &b) {
        return a.size() > b.size();
    });
    print_vector(arr2);

    return 0;
}