#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
	cin >> N;

    vector<long long> one(N + 1, 0);
    vector<long long> zero(N + 1, 0);

    one[0] = 0;
    zero[0] = 0;
    one[1] = 1;
    zero[1] = 0;

    for(int i = 2; i <= N; i++) {
        one[i] = zero[i - 1];
        zero[i] = one[i - 1] + zero[i - 1];
    }

    cout << one[N] + zero[N] << endl;

    return 0;
}