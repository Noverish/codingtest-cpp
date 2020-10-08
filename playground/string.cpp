#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str1 = "abcdefg";

    // reverse string
    reverse(str1.begin(), str1.end()); // gfedcba
    cout << str1 << "\n"; 

    // copy string reverse order
    string str2(str1.rbegin(), str1.rend()); // abcdefg
    cout << str2 << "\n";

    // compare with substring
    string str3 = "cdef";
    int tmp = str2.compare(2, 4, str3); // 0
    cout << tmp << "\n";

    return 0;
}
