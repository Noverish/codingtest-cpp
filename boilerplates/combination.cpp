#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // nCr
    int n = 5;
    int r = 2;

    // fill (r) trues and (n - r) falses
    vector<bool> onoff(n);
    fill(onoff.begin(), onoff.begin() + r, true);

    // combination through 0 ~ n
    do {
        for (int i = 0; i < n; i++) {
            if (onoff[i]) {
                cout << i << " ";
            }
        }
        cout << "\n";
    } while (prev_permutation(onoff.begin(), onoff.end()));

    // combination through vector
    vector<int> v = {10, 20, 30, 40, 50};
    do {
        for (int i = 0; i < n; i++) {
            if (onoff[i]) {
                cout << v[i] << " ";
            }
        }
        cout << "\n";
    } while (prev_permutation(onoff.begin(), onoff.end()));

    return 0;
}
