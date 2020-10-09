#include <algorithm>
#include <iostream>
#include <vector>

#define endl "\n"
#define MAX 2000
using namespace std;

int N, M;
bool visit[MAX];
vector<int> rel[MAX];

bool dfs(int node, int depth) {
    if (depth == 5) {
        return true;
    }

    visit[node] = true;
    for(int i = 0; i < rel[node].size(); i++) {
        int next = rel[node][i];
        if (!visit[next]) {
            bool result = dfs(next, depth + 1);
            if (result) {
                return true;
            }
        }
    }
    visit[node] = false;

    return false;
}


int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;
    int M; cin >> M;

    for(int i = 0; i < M; i++) {
        int a; cin >> a;
        int b; cin >> b;
        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    for(int i = 0; i < N; i++) {
        if (dfs(i, 1)) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}