#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int M; cin >> M;
    for(int i = 0; i < M; i++) {
        int num; cin >> num;
        cout << binary_search(v.begin(), v.end(), num) << " ";
    }
    cout << endl;

    return 0;
}