#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> stack;
    vector<int> answer(N, -1);
    stack.reserve(N);

    for(int i = 0; i < N; i++) {
        int num; cin >> num;

        while ((stack.size() > 0) && (stack.back().second < num)) {
            answer[stack.back().first] = num;
            stack.pop_back();
        }

        stack.push_back({ i, num });
    }

    for(int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}