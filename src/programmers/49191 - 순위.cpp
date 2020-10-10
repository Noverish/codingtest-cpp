#include <iostream>
#include <vector>

using namespace std;

vector<tuple<int, vector<vector<int>>>> inputs = {
    {5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}}}
};

int outputs[] = {
    2
};

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    for (vector<int> &r: results) {
        graph[r[0]][r[1]] = 1;
    }
    for (int k = 1; k <= n; k++) { // 거처가는 노드
        for (int i = 1; i <= n; i++) { // 출발 노드
            for (int j = 1; j <= n; j++) { // 끝 노드
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = 1;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] || graph[j][i]) {
                count++;
            }
        }
        if (count == n - 1) {
            answer++;
        }
    }
    return answer;
}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "49191 - 순위" << endl;
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