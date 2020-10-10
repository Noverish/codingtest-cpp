#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int R = 0, G = 1, B = 2;

    int N; cin >> N;
    int cache[N][3];
    for(int i = 0; i < N; i++) {
        cin >> cache[i][R];
        cin >> cache[i][G];
        cin >> cache[i][B];
    }

    int arr[N][3];
    int answer = INT_MAX;
    for(int x = 0; x < 3; x++) {
        arr[0][R] = (x == R) ? cache[0][R] : 1001;
        arr[0][G] = (x == G) ? cache[0][G] : 1001;
        arr[0][B] = (x == B) ? cache[0][B] : 1001;
        for(int i = 1; i < N; i++) {
            arr[i][R] = cache[i][R] + min(arr[i - 1][G], arr[i - 1][B]);
            arr[i][G] = cache[i][G] + min(arr[i - 1][R], arr[i - 1][B]);
            arr[i][B] = cache[i][B] + min(arr[i - 1][R], arr[i - 1][G]);
        }

        int local_answer = INT_MAX;
        for(int i = 0; i < 3; i++) {
            if (i != x) {
                local_answer = min(local_answer, arr[N - 1][i]);
            }
        }
        
        answer = min(answer, local_answer);
    }

    cout << answer << "\n";

    return 0;
}