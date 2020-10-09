#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"
#define N_MAX 1001
using namespace std;

int N, M, V;
vector<int> rel[N_MAX];
vector<bool> visit(N_MAX);

void dfs(int node) {
    cout << node << " ";
    visit[node] = true;
    for(int next: rel[node]) {
        if (!visit[next]) {
            dfs(next);
        }
    }
}

void bfs(int node) {
    queue<int> queue;
    queue.push(node);
    visit[node] = true;
    while(!queue.empty()) {
        int now = queue.front();
        cout << now << " ";
        queue.pop();
        for(int next: rel[now]) {
            if (!visit[next]) {
                queue.push(next);
                visit[next] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> N;
    cin >> M;
    cin >> V;

    for(int i = 0; i < M; i++) {
        int a; cin >> a;
        int b; cin >> b;
        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    for(int i = 0; i < N; i++) {
        sort(rel[i].begin(), rel[i].end());
    }

    dfs(V);
    cout << endl;
    fill(visit.begin(), visit.end(), false);
    bfs(V);
    cout << endl;

    return 0;
}