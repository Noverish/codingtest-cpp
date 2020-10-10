#include "../common.hpp"

vector<vector<int>> inputs = {
  {1, 22}
};

vector<vector<int>> outputs = {
  {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22}
};

vector<int> selfDividingNumbers(int left, int right) {
  vector<int> result;
  result.reserve(right - left + 1);

  for(int num = left; num <= right; num++) {
    int num2 = num;
    int possible = 1;
    while(num2) {
      int remainder = num2 % 10;
      if (remainder == 0 || num % remainder != 0) {
        possible = 0;
        break;
      }
      num2 = (num2 - remainder) / 10;
    }

    if (possible) {
      result.push_back(num);
    }
  }

  return result;
}

int main() {
  cout << "728. Self Dividing Numbers" << endl;
  for (int i = 0; i < inputs.size(); i++) {
    auto input = inputs[i];
    auto expected = outputs[i];
    auto real = selfDividingNumbers(input[0], input[1]);
    if(real == expected) {
      cout << "success" << endl;
    } else {
      cout << "failed" << endl;
      cout << expected << endl;
      cout << real << endl;
    }
  }
}
