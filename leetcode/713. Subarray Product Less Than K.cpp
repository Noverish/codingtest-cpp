#include "../common.hpp"

vector<tuple<vector<int>, int>> inputs = {
    {{10, 5, 2, 6}, 100}};

int outputs[] = {
    8};

int solution(vector<int>& nums, int k) {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (k <= 1) {
        return 0;
    }

    int prod = 1, left = 0, right = 0, answer = 0;
    for (right = 0; right < nums.size(); right++) {
        prod *= nums[right];
        while (prod >= k) {
            prod /= nums[left++];
        }
        answer += right - left + 1;
    }

    return answer;
}

int main() {
    cout << "713. Subarray Product Less Than K" << endl;
    for (int i = 0; i < inputs.size(); i++) {
        auto input = inputs[i];
        auto expected = outputs[i];
        auto real = solution(get<0>(input), get<1>(input));

        if (real == expected) {
            cout << "success" << endl;
        } else {
            cout << "failed" << endl;
            cout << expected << endl;
            cout << real << endl;
        }
    }
}