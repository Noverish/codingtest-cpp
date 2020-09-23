#include "../common.hpp"

vector<string> inputs = {
  "0110111",
  "101",
  "111111",
  "000",
  "1111110110111",
  "1111110110111001111111111",
};

int outputs[] = {
  9, 2, 21, 0, 30, 85
};

int numSub(string s) {
  int MODULO = 1e9 + 7;
  long result = 0;
  int now = 0;

  for(char c: s) {
    if (c == '1') {
      now++;
      continue;
    }

    if (now != 0) {
      result += (long) now * (now + 1) / 2;
      now = 0;
    }
  }

  if (now != 0) {
    result += (long) now * (now + 1) / 2;
  }

  return result % MODULO;
}

int main() {
  cout << "1513. Number of Substrings With Only 1s" << endl;
  for (int i = 0; i < inputs.size(); i++) {
    auto input = inputs[i];
    auto expected = outputs[i];
    auto real = numSub(input);

    if(real == expected) {
      cout << "success" << endl;
    } else {
      cout << "failed" << endl;
      cout << expected << endl;
      cout << real << endl;
    }
  }
}