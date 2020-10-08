#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    string str = "123 456 234 456";

    regex re("\\d{3}");
    smatch match;

    while(regex_search(str, match, re)) {
        std::cout << match.str() << '\n';
        str = match.suffix();
    }

    return 0;
}
