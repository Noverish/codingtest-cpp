#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl "\n"
using namespace std;

int N, I;
int neighbors[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

bool is_inside(int x, int y) {
    return (0 <= x) && (x < I) && (0 <= y) && (y < I);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int answer = 0;

    cin >> N;
    for (int n = 0; n < N; n++) {
        int x1, y1, x2, y2;
        cin >> I;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;

        vector<vector<int>> cache(I, vector<int>(I));
        queue<pair<int, int>> q;
        q.push({x1, y1});
        cache[x1][y1] = 1;

        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            int x = now.first;
            int y = now.second;
            int n = cache[x][y];

            if (x == x2 && y == y2) {
                answer = n;
                break;
            } 

            for(auto neighbor: neighbors) {
                int nx = x + neighbor[0];
                int ny = y + neighbor[1];

                if(is_inside(nx, ny) && !cache[nx][ny]) {
                    q.push({nx, ny});
                    cache[nx][ny] = n + 1;
                }
            }

        }

        cout << answer - 1 << endl;
    }

    return 0;
}