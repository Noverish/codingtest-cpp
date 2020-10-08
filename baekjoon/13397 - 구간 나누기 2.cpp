#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

typedef int Transform (int);

int lower_bound_descending(int left, int right, int val, Transform transform) {
    while(left < right) {
        int mid = (left + right) / 2;
        if (val >= transform(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

vector<int> cache(5000);
int N;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> N;
    int M; cin >> M;
    int MAX = 0, MIN = INT_MAX;
    for(int i = 0; i < N; i++) {
        cin >> cache[i];
        MAX = max(MAX, cache[i]);
        MIN = min(MIN, cache[i]);
    }

    int answer = lower_bound_descending(0, MAX - MIN, M, [](int num) {
        int sub_num = 0;
        int max1 = cache[0], min1 = cache[0];
        for(int i = 0; i < N; i++) {
            if (max1 < cache[i]) max1 = cache[i];
            if (min1 > cache[i]) min1 = cache[i];
            if (max1 - min1 > num) {
                max1 = cache[i];
                min1 = cache[i];
                sub_num++;
            }
        }
        return sub_num + 1;
    });

    cout << answer << "\n";
    
    return 0;
}