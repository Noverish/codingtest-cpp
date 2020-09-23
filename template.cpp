#include "../common.hpp"

vector<vector<string>> inputs = {
  
};

int outputs[] = {
  
};

int solution(string A, string B) {
  ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
}

int main() {
  cout << "title" << endl;
  for (int i = 0; i < inputs.size(); i++) {
    auto input = inputs[i];
    auto expected = outputs[i];
    auto real = solution(input[0], input[1]);

    if(real == expected) {
      cout << "success" << endl;
    } else {
      cout << "failed" << endl;
      cout << expected << endl;
      cout << real << endl;
    }
  }
}