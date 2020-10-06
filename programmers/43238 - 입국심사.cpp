#include "../common.hpp"

vector<tuple<int, vector<int>>> inputs = {
  {6, {7, 10}},
  {10, {1, 5}}
};

long long outputs[] = {
  28,
  9
};

long long solution(int n, vector<int> times) {
  ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

  long long left = 0;
  long long right = *max_element(times.begin(), times.end()) * n;

  while(left != right) {
    long long mid = (right + left) / 2;

    long long num = 0;
    for(long long time: times) {
      num += (mid / time);
    }

    if (num < n) {
      left = mid + 1;
    } else if (num > n) {
      right = mid - 1;
    } else {
      right = mid;
    }
  }

  return right;
}

int main() {
  cout << "43238 - 입국심사" << endl;
  for (int i = 0; i < inputs.size(); i++) {
    auto input = inputs[i];
    auto expected = outputs[i];
    auto real = solution(get<0>(input), get<1>(input));

    if(real == expected) {
      cout << "success" << endl;
    } else {
      cout << "failed" << endl;
      cout << expected << endl;
      cout << real << endl;
    }
  }
}