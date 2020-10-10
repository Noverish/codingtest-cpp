#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// Pair
template <typename K, typename V>
ostream& operator<<(ostream& out, const pair<K, V>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

// Vector
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

// Map
template <typename K, typename V>
ostream& operator<<(ostream& out, const unordered_map<K, V>& m) {
    for (const pair<K, V>& p : m) {
        out << "{" << p.first << ": " << p.second << "} ";
    }
    return out;
}

// Queue
template <typename T>
ostream& operator<<(ostream& out, queue<T> v) {
    out << "{";
    while(v.size()) {
        cout << v.front();
        if (v.size() > 1) {
            out << ", ";
        }
        v.pop();
    }
    out << "}";
    return out;
}
