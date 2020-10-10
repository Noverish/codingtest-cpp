#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> inputs = {
    {"ab", "ba"},
    {"ab", "ab"},
    {"aa", "aa"},
    {"aaaaaaabc", "aaaaaaacb"},
    {"", "aa"},
    {"abab", "abab"},
    {"abcdef", "fbcdea"},
    {"abac", "abad"},
};

bool outputs[] = {
    true,
    false,
    true,
    true,
    false,
    true,
    true,
    false,
};

bool buddyStrings(string A, string B) {
  if (A.length() != B.length()) {
    return false;
  }

  if (A == B) {
    int arr[26] = {};
    for (int i = 0; i < A.length(); i++) {
      int index = A[i] - 'a';
      if (arr[index] == 1) {
        return true;
      }
      arr[index]++;
    }
    return false;
  } else {
    int first = -1, second = -1;
    for (int i = 0; i < A.length(); i++) {
      if (A[i] != B[i]) {
        if (first == -1) {
          first = i;
        } else if (second == -1) {
          second = i;
        } else {
          return false;
        }
      }
    }

    if (first != -1 && second != -1) {
      return (A[first] == B[second]) && (A[second] == B[first]);
    } else {
      return false;
    }
  }
}

int main() {
  cout << "859. Buddy Strings" << endl;
  for (int i = 0; i < inputs.size(); i++) {
    auto input = inputs[i];
    auto expected = outputs[i];
    auto real = buddyStrings(input[0], input[1]);
    if(real == expected) {
      cout << "success" << endl;
    } else {
      cout << "failed" << endl;
      cout << expected << endl;
      cout << real << endl;
    }
  }
}