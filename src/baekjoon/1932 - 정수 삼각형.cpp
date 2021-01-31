#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define endl "\n"
using namespace std;

vector<int> arr1(600);
vector<int> arr2(600);
vector<int> arr3(600);
int N;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> N;
    cin >> arr1[0];

    for(int i = 1; i < N; i++) {
      for(int j = 0; j <= i; j++) {
        cin >> arr2[j];
      }

      for(int j = 0; j <= i; j++) {
        if (j == 0) {
          arr3[j] = arr2[j] + arr1[j];
        } else if (j == i) {
          arr3[j] = arr2[j] + arr1[j - 1];
        } else {
          arr3[j] = max(arr1[j - 1] + arr2[j], arr1[j] + arr2[j]);
        }
      }

      copy(arr3.begin(), arr3.end(), arr1.begin());
    }

    int max =  *max_element(arr1.begin(), arr1.end());

    cout << max;

    return 0;
}
