#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    out << "{";
    size_t last = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "}";
    return out;
}

int main() {
    // no duplicates: n! cases
    vector<int> arr = {2, 3, 1};
    sort(arr.begin(), arr.end());
    do {
        cout << arr << "\n";
    } while(next_permutation(arr.begin(), arr.end()));

    // with duplicates: n!/(n1!n2!...) cases
    vector<int> arr2 = {0, 1, 1, 1};
    sort(arr2.begin(), arr2.end());
    do {
        cout << arr2 << "\n";
    } while(next_permutation(arr2.begin(), arr2.end()));

    // string permutation
    string str1 = "acb";
    sort(str1.begin(), str1.end());
    do {
        cout << str1 << "\n";
    } while(next_permutation(str1.begin(), str1.end()));

    return 0;
}
