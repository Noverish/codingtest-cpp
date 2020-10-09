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

    for(int i = 0; i < M; i++) {
        int a; cin >> a;
        int b; cin >> b;
        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    int answer = 0;
    for(int i = 1; i <= N; i++) {
        if (!visit[i]) {
            answer++;
            bfs(i); // dfs(i);
        }
    }

    cout << answer << endl;

    return 0;
}