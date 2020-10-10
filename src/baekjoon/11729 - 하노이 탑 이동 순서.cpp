#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int from, int to, int num) {
    if (num == 1) {
        cout << from << " " << to << "\n";
        return;
    }

    int mid = 6 - from - to;
    solution(from, mid, num - 1);
    cout << from << " " << to << "\n";
    solution(mid, to, num - 1);
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;

    cout << (1 << N) - 1 << "\n";
    solution(1, 3, N);

    return 0;
}