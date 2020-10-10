#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    string str; cin >> str;

    int stack = 0;
    int answer = 0;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if (ch == '(') {
            stack++;
        } else {

            // 레이저
            if (str[i - 1] == '(') {
                stack--;
                answer += stack;
            // 막대 끝
            } else {
                answer += 1;
                stack--;
            }
        }
    }

    cout << answer << endl;

    return 0;
}