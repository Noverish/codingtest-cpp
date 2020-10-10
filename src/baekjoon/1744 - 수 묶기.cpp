#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;
    vector<int> minus;
    vector<int> plus;
    minus.reserve(N);
    plus.reserve(N);
    bool has_zero = false;
    int one_num = 0;

    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if (tmp > 1) {
            plus.push_back(tmp);
        } else if (tmp < 0) {
            minus.push_back(tmp);
        } else if (tmp == 0) {
            has_zero = true;
        } else {
            one_num++;
        }
    }

    sort(minus.begin(), minus.end());
    sort(plus.rbegin(), plus.rend());

    int sum = 0;
    for(int i = 0; (i + 1) < minus.size(); i += 2) {
        sum += minus[i] * minus[i + 1];
    }
    for(int i = 0; (i + 1) < plus.size(); i += 2) {
        sum += plus[i] * plus[i + 1];
    }

    if (plus.size() % 2 == 1) {
        sum += plus.back();
    }

    if (!has_zero && minus.size() % 2 == 1) {
        sum += minus.back();
    }

    cout << sum + one_num << "\n";

    return 0;
}