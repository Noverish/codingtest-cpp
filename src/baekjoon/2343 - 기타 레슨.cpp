#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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

vector<int> cache(100000);
int N;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> N;
    int M; cin >> M;
    int MAX = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> cache[i];
        MAX = max(MAX, cache[i]);
        sum += cache[i];
    }

    int answer = lower_bound_descending(MAX, sum, M, [](int num) {
        int bluray_length = 0;
        int bluray_num = 0;
        for(int i = 0; i < N; i++) {
            if (bluray_length + cache[i] > num) {
                bluray_num++;
                bluray_length = cache[i];
            } else {
                bluray_length += cache[i];
            }
        }
        return bluray_num + 1;
    });

    cout << answer << "\n";
    
    return 0;
}