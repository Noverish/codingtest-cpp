#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    vector<int> v = {3, 2, 4, 1, 5, 9};

    priority_queue<int> max_pq(v.begin(), v.end());
    cout << "first top: " << max_pq.top() << endl;
    max_pq.pop();
    cout << "second top: " << max_pq.top() << endl;
    max_pq.push(10);
    cout << "new top: " << max_pq.top() << endl;

    priority_queue<int, vector<int>, greater<int>> min_pq(v.begin(), v.end());
    cout << "first min: " << min_pq.top() << endl;
    min_pq.pop();
    cout << "second min: " << min_pq.top() << endl;
    min_pq.push(0);
    cout << "new min: " << min_pq.top() << endl;
}
