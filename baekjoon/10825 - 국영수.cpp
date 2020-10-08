#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<string, int, int, int> mtype;

int main() {
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int N; cin >> N;
    vector<tuple<string, int, int, int>> cache(N);
    for(int i = 0; i < N; i++) {
        cin >> get<0>(cache[i]);
        cin >> get<1>(cache[i]);
        cin >> get<2>(cache[i]);
        cin >> get<3>(cache[i]);
    }

    sort(cache.begin(), cache.end(), [](mtype &a, mtype &b) {
        if (get<1>(a) != get<1>(b)) {
            return get<1>(a) > get<1>(b);
        } else if (get<2>(a) != get<2>(b)) {
            return get<2>(a) < get<2>(b);
        } else if (get<3>(a) != get<3>(b)) {
            return get<3>(a) > get<3>(b);
        } else {
            return get<0>(a).compare(get<0>(b)) < 0;
        }
    });

    for(auto &v: cache) {
        cout << get<0>(v) << "\n";
    }

    return 0;
}