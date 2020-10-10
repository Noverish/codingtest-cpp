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
    while(left < right) {
        int mid = (left + right) / 2;
        if (val < transform(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
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
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5};

    auto lowerp = lower_bound(arr.begin(), arr.end(), 3);
    auto upperp = upper_bound(arr.begin(), arr.end(), 3);

    cout << "lower index: " << distance(arr.begin(), lowerp) << "\n";
    cout << "upper index: " << distance(arr.begin(), upperp) << "\n";
    
    // 나누어지는 수: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    //         몫: 0, 0, 1, 1, 1, 2, 2, 2, 3, 3
    // 3으로 나눈 몫이 2인 수 중에 가장 작은 수 (6)
    int num1 = custom_lower_bound(0, 10, 2, [](int a){ return a / 3; });
    cout << "lower: " << num1 << "\n";
    // 3으로 나눈 몫이 2인 수 중에 가장 큰 수 (8)
    int num2 = custom_upper_bound(0, 10, 2, [](int a){ return a / 3; });
    cout << "upper: " << num2 - 1 << "\n";

    // 나누는수: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    //     몫: 10, 5, 3, 2, 2, 1, 1, 1, 1,  1
    // 몫이 2인 나누는 수 중에 제일 작은 수 (4)
    int num3 = custom_lower_bound_descending(0, 10, 2, [](int a){ return 10 / a; });
    cout << "lower: " << num3 << "\n";
    // 몫이 2인 나누는 수 중에 제일 큰 수 (5)
    int num4 = custom_upper_bound_descending(0, 10, 2, [](int a){ return 10 / a; });
    cout << "upper: " << num4 - 1 << "\n";

    return 0;
}
