#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define MAX 10000
using namespace std;

int main() {
    vector<vector<int>> graph1 = { // a부터 b까지의 비용 c
        {4, 3, 3},
        {3, 4, 4},
        {3, 1, 2},
        {1, 4, 8},
        {1, 2, 5},
        {2, 1, 7},
        {2, 3, 9}
    };
    int VERTEX_NUM = 4;

    vector<vector<int>> rel(VERTEX_NUM + 1, vector<int>(VERTEX_NUM + 1, MAX));

    for(vector<int> &e: graph1) {
        rel[e[0]][e[1]] = e[2];
    }
    for(int i = 1; i <= VERTEX_NUM; i++) {
        rel[i][i] = 0;
    }

    for(int k = 1; k <= VERTEX_NUM; k++) {
        for(int i = 1; i <= VERTEX_NUM; i++) {
            for(int j = 1; j <= VERTEX_NUM; j++) {
                if (rel[i][k] + rel[k][j] < rel[i][j]) {
                    rel[i][j] = rel[i][k] + rel[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= VERTEX_NUM; i++) {
        for(int j = 1; j <= VERTEX_NUM; j++) {
            int d = rel[i][j];
            if (d == MAX) {
                cout << "_" << " ";
            } else {
                cout << d << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
