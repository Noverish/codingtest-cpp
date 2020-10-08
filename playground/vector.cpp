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
    vector<int> arr1;
    vector<int> arr2(10);
    vector<int> arr3(10, 1);
    vector<vector<int>> arr4(3, vector<int>(3, 2));

    cout << arr1 << endl;
    cout << arr2 << endl;
    cout << arr3 << endl;
    cout << arr4 << endl;

    cout << arr1.capacity() << endl;
    arr1.reserve(10);
    cout << arr1.capacity() << endl;

    vector<int> range_vector(arr3.begin(), arr3.begin() + 3);
    cout << range_vector << endl;
    cout << arr3 << endl;
    arr3[1] = 2;
    cout << range_vector << endl;
    cout << arr3 << endl;

    int sum = accumulate(arr1.begin(), arr1.end(), 0);

    return 0;
}
