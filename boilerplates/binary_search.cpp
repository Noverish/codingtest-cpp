#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef int Transform (int);

int custom_lower_bound(int left, int right, int val, Transform transform) {
    while(left < right) {
        int mid = (left + right) / 2;
        if (val <= transform(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int custom_upper_bound(int left, int right, int val, Transform transform) {
    while(left <= right) {
        int mid = (left + right) / 2;
        if (val < transform(mid)) {
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

int custom_lower_bound_descending(int left, int right, int val, Transform transform) {
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

int custom_upper_bound_descending(int left, int right, int val, Transform transform) {
    while(left <= right) {
        int mid = (left + right) / 2;
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

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5};

    auto lowerp = lower_bound(arr.begin(), arr.end(), 3);
    auto upperp = upper_bound(arr.begin(), arr.end(), 3);

    cout << "lower index: " << distance(arr.begin(), lowerp) << "\n";
    cout << "upper index: " << distance(arr.begin(), upperp) << "\n";
    
    //     x: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    // x / 3: 0, 0, 1, 1, 1, 2, 2, 2, 3,  3

    // x / 3 = 2 에서 x 의 최솟값 (1 <= x <= 10)
    int num11 = custom_lower_bound(1, 10, 2, [](int a){ return a / 3; });
    cout << "lower: " << num11 << "\n"; // 6

    // x / 3 = 0 에서 x 의 최솟값 (1 <= x <= 10)
    int num12 = custom_lower_bound(1, 10, 0, [](int a){ return a / 3; });
    cout << "lower: " << num12 << "\n"; // 1

    // x / 3 = 2 에서 x 의 최댓값 (1 <= x <= 10)
    int num21 = custom_upper_bound(1, 10, 2, [](int a){ return a / 3; });
    cout << "upper: " << num21 << "\n"; // 8

    // x / 3 = 3 에서 x 의 최댓값 (1 <= x <= 10)
    int num22 = custom_upper_bound(1, 10, 3, [](int a){ return a / 3; });
    cout << "upper: " << num22 << "\n"; // 10

    //      x:  1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    // 10 / x: 10, 5, 3, 2, 2, 1, 1, 1, 1,  1

    // 10 / x = 2 에서 x 의 최솟값 (1 <= x <= 10)
    int num31 = custom_lower_bound_descending(1, 10, 2, [](int a){ return 10 / a; });
    cout << "lower: " << num31 << "\n"; // 4

    // 10 / x = 10 에서 x 의 최솟값 (1 <= x <= 10)
    int num32 = custom_lower_bound_descending(1, 10, 10, [](int a){ return 10 / a; });
    cout << "lower: " << num32 << "\n"; // 1

    // 10 / x = 2 에서 x 의 최댓값 (1 <= x <= 10)
    int num41 = custom_upper_bound_descending(0, 10, 2, [](int a){ return 10 / a; });
    cout << "upper: " << num41 << "\n"; // 5

    // 10 / x = 1 에서 x 의 최댓값 (1 <= x <= 10)
    int num42 = custom_upper_bound_descending(0, 10, 1, [](int a){ return 10 / a; });
    cout << "upper: " << num42 << "\n"; // 10

    return 0;
}
