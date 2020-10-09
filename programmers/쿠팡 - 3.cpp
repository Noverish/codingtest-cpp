#include "../common.hpp"

#include <unordered_map>

vector<tuple<int, vector<int>>> inputs = {
    {3, {24,22,20,10,5,3,2,1}},
    {2, {1300000000,700000000,668239490,618239490,568239490,568239486,518239486,157658638,157658634,100000000,100}},
    {2, {1, 3, 6, 10, 15, 21}}
};

int outputs[] = {
    3, 4, 0
};

int solution(int k, vector<int> score) {
    unordered_map<int, vector<int>> map;
    vector<int> diff(score.size());

    for(int i = 1; i < score.size(); i++) {
        diff[i] = score[i - 1] - score[i];
        map[diff[i]].push_back(i);
    }

    vector<int> baddiff;
    for(const auto &p: map) {
        if (p.second.size() >= k) {
            baddiff.insert(baddiff.end(), p.second.begin(), p.second.end());
        }
    }
    sort(baddiff.begin(), baddiff.end());
    
    int last_badman = -1;
    int badman_num = 0;
    for(int d: baddiff) {
        if (last_badman != d - 1) {
            badman_num++;
        }
        badman_num++;
        last_badman = d;
    }

    if (badman_num == 0) {
        return 0;
    } else {
        return score.size() - badman_num;
    }
}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "쿠팡 - 3" << endl;
    for (int i = 0; i < inputs.size(); i++) {
        auto input = inputs[i];
        auto expected = outputs[i];
        auto real = solution(get<0>(input), get<1>(input));

        if (real == expected) {
            cout << GREEN << "success" << NO_COLOR << endl;
        } else {
            cout << RED << "failed" << endl;
            cout << "  real:     "  << real << endl;
            cout << "  expected: " << expected << NO_COLOR << endl;
        }
    }
}