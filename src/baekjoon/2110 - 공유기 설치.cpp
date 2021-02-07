#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../print_utils.hpp"

#define endl "\n"
using namespace std;

typedef int Transform (int);
int N, C;
vector<int> arr;

int custom_upper_bound_descending(int left, int right, int val, Transform transform) {
    while(left < right) {
        int mid = (left + right) / 2;
        if (val > transform(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> N;
    arr = vector<int>(N);
    cin >> C;
    for(int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    // cout << "C : " << C << endl;

    int len = arr[N - 1] - arr[0] + 1;

    int answer = custom_upper_bound_descending(1, len, C, [](int min_distance){
        cout << "min_distance: " << min_distance << endl;
        int num = 1;
        int prev_location = arr[0];
        for(int i = 1; i < N; i++) {
            int curr_location = arr[i];
            cout << "prev: " << prev_location << ", curr: " << curr_location << ", num: " << num << endl;
            if(curr_location - prev_location < min_distance) {
                
            } else {
                num++;
                prev_location = curr_location;
            }
        }
        return num;
    });

    cout << answer - 1 << endl;

    return 0;
}
