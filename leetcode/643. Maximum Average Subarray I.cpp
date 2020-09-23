#include "../common.hpp"

vector<vector<int>> inputs1 = {
  {1,12,-5,-6,50,3},
  {5},
  {0,4,0,3,2}
};
vector<int> inputs2 = {
  4,
  1,
  1
};

double outputs[] = {
  12.75,
  5,
  4
};

double findMaxAverage(vector<int>& nums, int k) {
  int now_sum = 0;

  for(int i = 0; i < k; i++) {
    now_sum += nums[i];
  }

  int maximum = now_sum;

  for(int i = k; i < nums.size(); i++) {
    now_sum += nums[i] - nums[i - k];
    maximum = max(maximum, now_sum);
  }

  return (double) maximum / k;
}

int main() {
  cout << "643. Maximum Average Subarray I" << endl;
  for (int i = 0; i < inputs1.size(); i++) {
    auto input1 = inputs1[i];
    auto input2 = inputs2[i];
    auto expected = outputs[i];
    auto real = findMaxAverage(input1, input2);

    if(real == expected) {
      cout << "success" << endl;
    } else {
      cout << "failed" << endl;
      cout << expected << endl;
      cout << real << endl;
    }
  }
}