// Problem: https://www.geeksforgeeks.org/ugly-numbers/
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <cmath>
#include "../print_utils.hpp"

using namespace std;

vector<int> inputs = {
    7, 10, 15, 150, 4
};

int outputs[] = {
    8, 12, 24, 5832, 4
};

int solution(int n) {
    vector<int> cache(n);
    int pivot2 = 0, pivot3 = 0, pivot5 = 0;
    cache[0] = 1;

    for(int i = 1; i < n; i++) {
        vector<int> tmp = { cache[pivot2] * 2, cache[pivot3] * 3, cache[pivot5] * 5 };
        int min_num = *min_element(tmp.begin(), tmp.end());
        cache[i] = min_num;

        if (tmp[0] == min_num) {
            pivot2++;
        }
        if (tmp[1] == min_num) {
            pivot3++;
        }
        if (tmp[2] == min_num) {
            pivot5++;
        }
    }

    return cache[n - 1];
}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "ugly-numbers" << endl;
    for (int i = 0; i < inputs.size(); i++) {
        auto input = inputs[i];
        auto expected = outputs[i];
        auto real = solution(input);

        if (real == expected) {
            cout << GREEN << "success" << NO_COLOR << endl;
        } else {
            cout << RED << "failed" << endl;
            cout << "  real:     "  << real << endl;
            cout << "  expected: " << expected << NO_COLOR << endl;
        }
    }
}
