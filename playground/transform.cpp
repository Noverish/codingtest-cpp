#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
void print_vector(vector<T> &arr) {
    for(auto it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {10,20,30,40,50};

    transform(arr1.begin(), arr1.end(), arr2.begin(), arr1.begin(), plus<int>());
    
    // arr1 = {11, 22, 33, 44, 55};
    print_vector(arr1);

    transform(arr1.begin(), arr1.end(), arr1.begin(), [](const int a) { return a + 1; });

    // arr1 = {12, 23, 34, 45, 56};
    print_vector(arr1);

    return 0;
}