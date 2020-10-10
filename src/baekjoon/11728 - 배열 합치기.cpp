#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;
    int M; cin >> M;
    vector<int> v1(N);
    vector<int> v2(M);
    vector<int> v3(N + M);

    for(int i = 0; i < N; i++) {
        cin >> v1[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> v2[i];
    }

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    for(int i = 0; i < N + M; i++) {
        cout << v3[i] << " ";
    }
    cout << endl;

    return 0;
}