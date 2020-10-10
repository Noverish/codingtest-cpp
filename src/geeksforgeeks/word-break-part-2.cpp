#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void solution(vector<string> &words, string str, string result) {
    // cout << str << " " << result << endl;
    int n = str.size();

    for(int i = 0; i <= n; i++) {
        string prefix = str.substr(0, i);
        
        auto pointer = find(words.begin(), words.end(), prefix);
        if (pointer != words.end()) {
            // cout << i << " " << n << endl;
            if (i == n) {
                result += prefix;
                cout << "(" << result << ")";
                return;
            }
            solution(words, str.substr(i, n-i), result + prefix + " ");
        }
    }
}

int main() {
    int T, N;
    vector<string> words;
    string str, tmp;

	cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N;
        
        words.clear();
        words.reserve(N);
    	for(int j = 0; j < N; j++) {
    	    cin >> tmp;
    	    words.push_back(tmp);
    	}
    	cin >> str;

    	solution(words, str, "");

        cout << endl;
    }
    return 0;
}