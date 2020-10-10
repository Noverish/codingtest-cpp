// problem: https://app.codility.com/programmers/lessons/17-dynamic_programming/min_abs_sum
// helps: https://bgrooot.github.io/codility-minabssum/
// result: https://app.codility.com/demo/results/trainingYAVV88-YU7/

#include <unordered_map>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

vector<vector<int>> inputs = {
    {1, 5, 2, -2}
};

int outputs[] = {
    0
};

int solution(vector<int> &A) {
    transform(A.begin(), A.end(), A.begin(), [](int a) { return (a > 0) ? a : -a; }); // make abs
    int sum = accumulate(A.begin(), A.end(), 0);
    unordered_map<int, int> map;
    vector<int> subset(max(sum, 1), -1);
    subset[0] = 0;
    
    for(int num: A) {
        map[num]++;
    }

    for(const auto &pair: map) {
        for(int i = 0; i < sum / 2 + 1; i++) {
            if (subset[i] >= 0) {
                subset[i] = pair.second;
            } else if (i >= pair.first && subset[i - pair.first] > 0){
                subset[i] = subset[i - pair.first] - 1;
            }
        }
    }

    int answer = sum;
    for(int i = 0; i < sum / 2 + 1; i++) {
        if (subset[i] >= 0) {
            answer = min(answer, sum - i * 2);
        }
    }

    return answer;
}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "MinAbsSum" << endl;
    for (int i = 0; i < inputs.size(); i++) {
        auto input = inputs[i];
        auto expected = outputs[i];
        auto real = solution(input);

        if (real == expected) {
            cout << GREEN << "success" << NO_COLOR << endl;
        } else {
            cout << RED << "failed" << endl;
            cout << "  real:     "  << real << endl;
            cout << "  expected: " << expected << NO_COLOR << endl;
        }
    }
}
