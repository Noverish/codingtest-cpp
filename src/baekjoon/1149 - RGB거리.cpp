#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    out << "{";
    size_t last = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "}";
    return out;
}

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;
    vector<int> r(N + 1);
    vector<int> g(N + 1);
    vector<int> b(N + 1);

    for(int i = 1; i <= N; i++) {
        cin >> r[i];
        cin >> g[i];
        cin >> b[i];

        r[i] += min(g[i - 1], b[i - 1]);
        g[i] += min(r[i - 1], b[i - 1]);
        b[i] += min(r[i - 1], g[i - 1]);
    }

    cout << min({r[N], g[N], b[N]}) << "\n";

    return 0;
}