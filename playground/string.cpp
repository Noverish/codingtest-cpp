#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str1 = "abcdefg";

    cout << str1 << "\n"; // abcdefg
    reverse(str1.begin(), str1.end());
    cout << str1 << "\n"; // gfedcba

    string str2(str1.rbegin(), str1.rend());
    cout << str2 << "\n"; // abcdefg

    string str3 = "cdef";
    int tmp = str2.compare(2, 4, str3);
    cout << tmp << "\n"; // 0

    return 0;
}
