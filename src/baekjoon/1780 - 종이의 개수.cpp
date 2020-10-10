#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <cmath>

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

vector<int> solution(vector<vector<int>> &arr, int x1, int y1, int x2, int y2) {
    if (x1 + 1 == x2 && y1 + 1 == y2) {
        vector<int> tmp(3, 0);
        tmp[arr[x1][y1] + 1] = 1;
        return tmp;
    }

    vector<int> tmp2(3, 0);
    int size = (x2 - x1) / 3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int x11 = x1 + i * size;
            int x22 = x1 + (i + 1) * size;
            int y11 = y1 + j * size;
            int y22 = y1 + (j + 1) * size;

            vector<int> result = solution(arr, x11, y11, x22, y22);

            transform(result.begin(), result.end(), tmp2.begin(), tmp2.begin(), plus<int>());
        }
    }

    vector<int> a1 = {9, 0, 0};
    vector<int> a2 = {0, 9, 0};
    vector<int> a3 = {0, 0, 9};

    if (tmp2 == a1) {
        return {1, 0, 0};
    }
    if (tmp2 == a2) {
        return {0, 1, 0};
    }
    if (tmp2 == a3) {
        return {0, 0, 1};
    }

    cout << x1 << y1 << x2 << y2 << tmp2 << endl;

    return tmp2;
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> result = solution(arr, 0, 0, N, N);

    for(int value: result) {
        cout << value << endl;
    }

    return 0;
}