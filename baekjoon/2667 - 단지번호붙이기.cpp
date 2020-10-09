#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define endl "\n"
#define MAX 25 + 2
using namespace std;

int cache[MAX][MAX];
int visit[MAX][MAX];
int neighbors[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N;

int bfs(int a, int b, int new_danzi) {
    int new_danzi_size = 0;
    queue<pair<int, int>> queue;
    queue.push({a, b});
    visit[a][b] = 1;
    cache[a][b] = new_danzi;
    new_danzi_size++;
    while(!queue.empty()) {
        int i = queue.front().first;
        int j = queue.front().second;
        queue.pop();

        for(auto neighbor: neighbors) {
            int new_i = i + neighbor[0];
            int new_j = j + neighbor[1];
            if (cache[new_i][new_j] == 1 && visit[new_i][new_j] == 0) {
                visit[new_i][new_j] = 1;
                cache[new_i][new_j] = new_danzi;
                queue.push({new_i, new_j});
                new_danzi_size++;
            }
        }
    }

    return new_danzi_size;
}

int main() {
    // ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> N;
    vector<int> danzi;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%1d", &cache[i][j]);
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if (cache[i][j] == 1) {
                int new_danzi_size = bfs(i, j, danzi.size() + 2);
                danzi.push_back(new_danzi_size);
            }
        }
    }

    sort(danzi.begin(), danzi.end());

    cout << danzi.size() << endl;
    for(int i = 0; i < danzi.size(); i++) {
        cout << danzi[i] << endl;
    }

    return 0;
}