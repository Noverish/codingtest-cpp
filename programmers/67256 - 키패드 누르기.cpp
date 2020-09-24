#include "../common.hpp"

vector<tuple<vector<int>, string>> inputs = {
  {{1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right"},
  {{7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left"},
  {{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "right"}
};

vector<string> outputs = {
  "LRLLLRLLRRL",
  "LRLLRRLLLRR",
  "LLRLLRLLRL"
};

int dist(int n, int m) {
  if (n == 0) {
    n = 11;
  }
  if (m == 0) {
    m = 11;
  }
  n--;
  m--;
  int m1 = floor(m / 3);
  int m2 = m % 3;
  if (n == 1 || n == 4 || n == 7 || n == 10) {
    int n1 = floor(n / 3);
    int n2 = n % 3;
    return abs(n1 - m1) + ((n2 != m2) ? 1 : 0);
  } else {
    return -1;
  }
}

string solution(vector<int> numbers, string hand) {
  ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

  int leftHand = 10, rightHand = 12;
  bool isRight = hand == "right";
  string result;
  result.reserve(numbers.size());

  for(int n : numbers) {
    int useLeft = false;

    if (n > 0 && n % 3 == 1) {
      useLeft = true;
    } else if (n > 0 && n % 3 == 0) {
      useLeft = false;
    } else {
      int leftHandDist = dist(n, leftHand);
      int rightHandDist = dist(n, rightHand);

      if (leftHandDist < rightHandDist) {
        useLeft = true;
      } else if (leftHandDist > rightHandDist) {
        useLeft = false;
      } else {
        if (isRight) {
          useLeft = false;
        } else {
          useLeft = true;
        }
      }
    }

    result.append(useLeft ? "L" : "R");
    if (useLeft) {
      leftHand = n;
    } else {
      rightHand = n;
    }
  }

  return result;
}

int main() {
  cout << "67256 - 키패드 누르기" << endl;
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