#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define endl "\n"
using namespace std;

int N, M;
int neighbors[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool is_inside(int i, int j) {
    return (0 <= i) && (i < N) && (0 <= j) && (j < M);
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> M;
    cin >> N;
    vector<vector<int>> cache(N, vector<int>(M));
    queue<pair<int, int>> q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> cache[i][j];

            if (cache[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int MAX = 0;
    while(!q.empty()) {
        auto now = q.front();
        q.pop();
        for(auto neighbor: neighbors) {
            int ni = now.first + neighbor[0];
            int nj = now.second + neighbor[1];
            int nn = cache[now.first][now.second];
            MAX = max(MAX, nn);

            if (is_inside(ni, nj) && cache[ni][nj] == 0) {
                cache[ni][nj] = nn + 1;
                q.push({ ni, nj });
            }
        }
    }

    bool unreached = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (cache[i][j] == 0) {
                unreached = true;
            }
        }
    }

    if (unreached) {
        cout << -1 << endl;
    } else {
        cout << MAX - 1 << endl;
    }

    return 0;
}