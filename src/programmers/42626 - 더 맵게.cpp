#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<tuple<vector<int>, int>> inputs = {
    {{1, 2, 3, 9, 10, 12}, 7}
};

int outputs[] = {
    2
};

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    int answer = 0;
    while(pq.size() >= 2) {
        if (pq.top() >= K) {
            return answer;
        }

        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int n = a + 2 * b;
        pq.push(n);
        answer++;
    }

    if (pq.size() == 1 && pq.top() >= K) {
        return answer;
    }

    return -1;
}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "42626 - 더 맵게" << endl;
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