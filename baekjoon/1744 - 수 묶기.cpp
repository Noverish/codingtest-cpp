#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;
    vector<tuple<string, int, int, int>> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> get<0>(arr[i]);
        cin >> get<1>(arr[i]);
        cin >> get<2>(arr[i]);
        cin >> get<3>(arr[i]);
    }

    return 0;
}