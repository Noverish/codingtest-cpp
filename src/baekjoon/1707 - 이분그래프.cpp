#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl "\n"
#define MAX 20001
#define RED 1
#define BLU 2
using namespace std;

int N, M, V;
vector<int> rel[MAX];
vector<int> visit(MAX);

bool dfs(int node, int parent_color) {
    visit[node] = parent_color == RED ? BLU : RED;
    for(int next: rel[node]) {
        if (visit[next]) {
            if (visit[next] == visit[node]) {
                return false;
            }
        } else {
            if (!dfs(next, visit[node])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> N;
    for(int x = 0; x < N; x++) {
        int V; cin >> V;
        int E; cin >> E;

        fill(visit.begin(), visit.end(), 0);
        for(int i = 0; i < MAX; i++) {
            rel[i].clear();
        }

        for(int i = 0; i < E; i++) {
            int a; cin >> a;
            int b; cin >> b;
            rel[a].push_back(b);
            rel[b].push_back(a);
        }

        bool answer = true;
        for(int i = 1; i <= V; i++) {
            if (!visit[i]) {
                if (!dfs(i, RED)) {
                    answer = false;
                    break;
                }
            }
        }

        if (answer) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}