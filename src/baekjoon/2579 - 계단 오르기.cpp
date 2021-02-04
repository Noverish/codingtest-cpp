#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl "\n"
using namespace std;

vector<int> arr;
vector<int> f; // 전 점프가 한 계단 점프
vector<int> g; // 전 점프가 두 계단 점프
int N;

void asdf(int n) {
    if (n <= 0) {
        f[0] = arr[0];
    } else if (n == 1) {
        f[1] = arr[0] + arr[1];
        g[1] = arr[1];
    } else {
        int v = arr[n];
        f[n] = v + g[n - 1];
        g[n] = v + max(f[n - 2], g[n - 2]);
    }
}

int main() {
    ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

    cin >> N;
    arr = vector<int>(N);
    f = vector<int>(N);
    g = vector<int>(N);

    for (int j = 0; j < N; j++) {
        cin >> arr[j];
        asdf(j);
    }

    
    cout << max(f[N - 1], g[N - 1]) << endl;

    return 0;
}
