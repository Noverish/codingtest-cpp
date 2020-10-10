#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int MOD = 1000000000;

    int N; cin >> N;
    int K; cin >> K;
    vector<vector<int>> cache(K + 1, vector<int>(N + 1));

    for(int i = 0; i <= N; i++) {
        cache[1][i] = i + 1;
    }

    for(int k = 2; k <= K; k++) {
        for(int n = 0; n <= N; n++) {
            cache[k][n] = (cache[k][n - 1] + cache[k - 1][n]) % MOD;
        }
    }

    cout << (cache[K][N] + MOD - cache[K][N - 1]) % MOD << "\n";

    return 0;
}