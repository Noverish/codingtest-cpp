#include <iostream>
#include <vector>
#include <numeric>

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
    // vector initialization
    vector<int> arr1; // {}
    vector<int> arr2(10); // {0, 0, ... 0}
    vector<int> arr3(10, 1); // {1, 1, ... 1}
    vector<vector<int>> arr4(3, vector<int>(3, 2)); // {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}

    // vector capacity end reserve;
    cout << arr1.capacity() << endl; // 0
    arr1.reserve(10);
    cout << arr1.capacity() << endl; // 10

    // vector parital copy
    vector<int> range_vector(arr3.begin(), arr3.begin() + 3);

    // reduce function
    vector<int> arr5 = {1, 2, 3, 4};
    int sum = accumulate(arr5.begin(), arr5.end(), 0); // 10
    int mux = accumulate(arr5.begin(), arr5.end(), 1, [](int a, int b) { return a * b; }); // 24
    cout << "sum: " << sum << "\n";
    cout << "mux: " << mux << "\n";

    // fill vector with incresing number
    vector<int> arr6(5);
    iota(arr6.begin(), arr6.end(), 0); // {0, 1, 2, 3, 4}
    cout << "iota ascending order: " << arr6 << "\n";
    iota(arr6.rbegin(), arr6.rend(), 0); // {4, 3, 2, 1, 0}
    cout << "iota descending order: " << arr6 << "\n";

    // union two vector
    vector<int> arr7 = {1, 2, 3, 4, 5};
    vector<int> arr8 = {10,20,30,40,50};
    transform(arr7.begin(), arr7.end(), arr8.begin(), arr8.begin(), plus<int>()); // arr8 = {11, 22, 33, 44, 55}
    cout << "add element by element: " << arr8 << "\n";

    // map function
    transform(arr7.begin(), arr7.end(), arr7.begin(), [](int a) { return 2 * a; }); // arr7 = {2, 4, 6, 8, 10}
    cout << "double each element: " << arr7 << "\n";

    return 0;
}
