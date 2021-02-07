#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../print_utils.hpp"

#define endl "\n"
using namespace std;

int N, M;
vector<int> arr;

int exist(int n) {
  return binary_search(arr.begin(), arr.end(), n);
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> N;
    arr = vector<int>(N);
    for(int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cin >> M;
    for(int i = 0; i < M; i++) {
      int tmp;
      cin >> tmp;
      cout << exist(tmp) << endl;
    }

    return 0;
}
