// 시간 초과
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string from, string to) {
    if (from.size() == to.size()) {
        return false;
    }

    string appendA = from + 'A';
    if (appendA == to) {
        return true;
    }

    string appendB = from + 'B';
    reverse(appendB.begin(), appendB.end());
    if (appendB == to) {
        return true;
    }

    return solution(appendA, to) || solution(appendB, to);
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    string s1; cin >> s1;
    string s2; cin >> s2;

    cout << solution(s1, s2) << "\n";

    return 0;
}