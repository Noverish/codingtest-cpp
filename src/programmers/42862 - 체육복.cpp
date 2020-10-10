#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, vector<int>, vector<int>>> inputs = {
    {5, {2, 4}, {1, 3, 5}},
    {5, {2, 4}, {3}},
    {3, {3}, {1}},
    {5, {2, 3}, {3, 4}}
};

int outputs[] = {
    5, 4, 2, 4
};

int solution(int n, vector<int> lost, vector<int> reserve) {
    ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

    int ediots[31] = {0};
    int ediots_num = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int l = 0, r = 0;
    while(l < lost.size() && r < reserve.size()) {
        if (lost[l] < reserve[r]) {
            l++;
        } else if (lost[l] > reserve[r]) {
            r++;
        } else {
            ediots[lost[l]] = 1;
            ediots_num++;
            l++;
            r++;
        }
    }

    l = 0;
    r = 0;
    int result = 0;

    while(l < lost.size() && r < reserve.size()) {
        int ll = lost[l];
        int rr = reserve[r];

        if (ediots[ll] == 1) {
            l++;
            continue;
        }

        if (ediots[rr] == 1) {
            r++;
            continue;
        }

        int diff = rr - ll;
        if (-1 <= diff && diff <= 1) {
            result++;
            l++;
            r++;
        } else {
            if (ll < rr) {
                l++;
            } else {
                r++;
            }
        }
    }

    return n - lost.size() + result + ediots_num;
}

int main() {
    cout << "42862 - 체육복" << endl;
    for (int i = 0; i < inputs.size(); i++) {
        auto input = inputs[i];
        auto expected = outputs[i];
        auto real = solution(get<0>(input), get<1>(input), get<2>(input));

        if (real == expected) {
            cout << "success" << endl;
        } else {
            cout << "failed" << endl;
            cout << expected << endl;
            cout << real << endl;
        }
    }
}