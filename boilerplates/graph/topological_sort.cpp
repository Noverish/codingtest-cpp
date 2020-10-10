#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
    vector<pair<int, int>> edges = {{3, 5}, {2, 3}, {0, 2}, {1, 3}, {4, 5}, {0, 3}, {2, 5}, {1, 4}};
    int VERTEX_NUM = 6;

    vector<int> rel[VERTEX_NUM];
    vector<int> enter(VERTEX_NUM);
    vector<int> result(VERTEX_NUM);

    for(pair<int, int> &e: edges) {
        int a = e.first;
        int b = e.second;
        rel[a].push_back(b);
        enter[b]++;
    }

    queue<int> q;
    for(int i = 0; i < VERTEX_NUM; i++) {
        if (enter[i] == 0) {
            q.push(i);
        }
    }

    for(int i = 0; i < VERTEX_NUM; i++) {
        if (q.empty()) {
            cout << "cycle!!" << endl;
            return 0;
        }

        int now = q.front();
        q.pop();
        result[i] = now;
        for(int next: rel[now]) {
            if (--enter[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << result << endl;

    return 0;
}
