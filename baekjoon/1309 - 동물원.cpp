#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;
    vector<int> left(N + 1);
    vector<int> right(N + 1);
    vector<int> none(N + 1);

    left[1] = 1;
    right[1] = 1;
    none[1] = 1;

    for(int i = 2; i <= N; i++) {
        left[i] = (none[i - 1] + right[i - 1]) % 9901;
        right[i] = (none[i - 1] + left[i - 1]) % 9901;
        none[i] = (left[i - 1] + right[i - 1] + none[i - 1]) % 9901;
    }
    
    int left_sum = accumulate(left.begin(), left.end(), 0);
    int right_sum = accumulate(right.begin(), right.end(), 0);

    cout << (left_sum + right_sum + 1) % 9901 << "\n";

    return 0;
}