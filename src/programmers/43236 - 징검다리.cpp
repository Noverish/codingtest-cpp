#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, vector<int>, int>> inputs = {
    {25, {2, 14, 11, 21, 17}, 2}
};

int outputs[] = {
    4
};

typedef int Transform (int);
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

vector<int> global_rocks;

int solution(int distance, vector<int> rocks, int n) {
    rocks.resize(rocks.size() + 1);
    rocks[rocks.size() - 1] = distance;
    sort(rocks.begin(), rocks.end());
    for(int i = rocks.size() - 1; i > 0; i--) {
        rocks[i] -= rocks[i - 1];
    }
    int min = *min_element(rocks.begin(), rocks.end());

    // rocks = {2, 9, 3, 3, 4, 4};
    global_rocks = rocks;

    int i = custom_upper_bound(min, distance, n, [](int min_of_dis) {
        int tmp_dis = 0;
        int tmp_num = 0;
        for(int rock: global_rocks) {
            if (tmp_dis + rock < min_of_dis) {
                tmp_num++;
                tmp_dis += rock;
            } else {
                tmp_dis = 0;
            }
        }
        return tmp_num;
    });
    
    return i - 1;
}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "43236 - 징검다리" << endl;
    for (int i = 0; i < inputs.size(); i++) {
        auto input = inputs[i];
        auto expected = outputs[i];
        auto real = solution(get<0>(input), get<1>(input), get<2>(input));

        if (real == expected) {
            cout << GREEN << "success" << NO_COLOR << endl;
        } else {
            cout << RED << "failed" << endl;
            cout << "  real:     "  << real << endl;
            cout << "  expected: " << expected << NO_COLOR << endl;
        }
    }
}