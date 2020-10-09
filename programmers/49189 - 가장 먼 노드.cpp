#include "../common.hpp"

vector<tuple<int, vector<vector<int>>>> inputs = {
    {6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}}}
};

int outputs[] = {
    3
};

int solution(int n, vector<vector<int>> edge) {
  
    vector<int> tree(n + 1, 0);
    vector<int> visit(n + 1);
    vector<int> rel[n + 1];

    for(vector<int> node: edge) {
        int a = node[0];
        int b = node[1];
        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    tree[1] = 0;
    visit[1] = 1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int next: rel[now]) {
            if(!visit[next]) {
                tree[next] = tree[now] + 1;
                visit[next] = 1;
                q.push(next);
            }
        }
    }

    int MAX = *max_element(tree.begin(), tree.end());
    int num = 0;
    for(int t: tree) {
        if (t == MAX) {
            num++;
        }
    }

    return num;
}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "49189 - 가장 먼 노드" << endl;
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