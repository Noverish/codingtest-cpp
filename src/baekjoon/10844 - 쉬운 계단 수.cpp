#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<vector<long long>> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    int M = 1000000000;
    cin >> N;

    vector<vector<long long>> arr(N + 1, vector<long long>(10, 0));

    for(int i = 1; i <= 9; i++) {
        arr[1][i] = 1;
    }

    for(int i = 2; i <= N; i++) {

        arr[i][0] = arr[i - 1][1];
        arr[i][9] = arr[i - 1][8];

        for(int j = 1; j <= 8; j++) {
            arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % M;
        }
    }

    long long answer = 0;
    for(int i = 0; i <= 9; i++) {
        answer += arr[N][i] % 1000000000;
    }
    cout << answer % 1000000000 << endl;

    return 0;
}