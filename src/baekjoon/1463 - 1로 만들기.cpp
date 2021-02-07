#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include "../print_utils.hpp"

#define endl "\n"
using namespace std;

int N;
vector<int> arr;
queue<int> q;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> N;
    arr = vector<int>(N, 0);
    q.push(1);

    if (N == 1) {
        cout << "0" << endl;
        return 0;
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        int tmp[3] = {v + 1, v * 2, v * 3};
        for(int new_v : tmp) {
            if (new_v < N) {
                if (arr[new_v] == 0) {
                    arr[new_v] = arr[v] + 1;
                    q.push(new_v);
                }
            } else if (new_v == N) {
                cout << arr[v] + 1 << endl;
                return 0;
            }
        }
        cout << arr << endl;
    }

    return 0;
}
