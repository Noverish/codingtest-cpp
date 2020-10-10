#include <vector>
#include <tuple>
#include <string>
#include <iostream>

using namespace std;

vector<tuple<string, string>> inputs = {

};

int outputs[] = {

};

int solution(string A, string B) {

}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "title" << endl;
    for (int i = 0; i < inputs.size(); i++) {
        auto input = inputs[i];
        auto expected = outputs[i];
        auto real = solution(get<0>(input), get<1>(input));

        if (real == expected) {
            cout << GREEN << "success" << NO_COLOR << endl;
        } else {
            cout << RED << "failed" << endl;
            cout << "  real:     "  << real << endl;
            cout << "  expected: " << expected << NO_COLOR << endl;
        }
    }
}
