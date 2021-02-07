#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl "\n"
using namespace std;
typedef uint64_t Transform (uint64_t);

int K, N;
vector<int> arr;

uint64_t custom_upper_bound_descending(uint64_t left, uint64_t right, uint64_t val, Transform transform) {
    while(left <= right) {
        uint64_t mid = (left + right) / 2;
        if (val > transform(mid)) {
            if (left == right) {
                break;
            } else {
                right = mid;
            }
        } else {
            left = mid + 1;
        }
    }
    return left - 1;
}

uint64_t calc_num(uint64_t length) {
    uint64_t num = 0;
    for(uint64_t v : arr) {
        num += v / length;
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> K;
    cin >> N;
    arr = vector<int>(K);
    for(int i = 0; i < K; i++) {
      cin >> arr[i];
    }

    uint64_t max_v = *max_element(arr.begin(), arr.end());

    uint64_t ans = custom_upper_bound_descending(1, max_v, N, calc_num);

    cout << ans << endl;

    return 0;
}