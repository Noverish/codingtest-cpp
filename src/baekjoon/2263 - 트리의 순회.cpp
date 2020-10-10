#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> inorder(100000);
vector<int> postorder(100000);
vector<int> cache(100000);

void solution(int inorder_start, int inorder_end, int postorder_start, int postorder_end) {
    if (inorder_start > inorder_end || postorder_start > postorder_end) {
        return;
    }

    int root = postorder[postorder_end];
    int i = cache[root];
    cout << root << " ";
    solution(inorder_start, i - 1, postorder_start, postorder_start + (i - inorder_start) - 1);
    solution(i + 1, inorder_end, postorder_start + (i - inorder_start), postorder_end - 1);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }

    for (int i = 0; i < N; i++) {
        cache[inorder[i]] = i;
    }

    solution(0, N - 1, 0, N - 1);

    return 0;
}