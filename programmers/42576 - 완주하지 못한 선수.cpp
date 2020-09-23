#include "../common.hpp"

vector<vector<vector<string>>> inputs = {
  {{"leo", "kiki", "eden"}, {"eden", "kiki"}},
  {{"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}},
  {{"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}}
};

vector<string> outputs = {
  "leo",
  "vinko",
  "mislav"
};

string solution(vector<string> participant, vector<string> completion) {
  ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  unordered_map<string, int> status;

  for(string v: participant) {
    if (status[v]) {
      status[v] += 1;
    } else {
      status[v] = 1;
    }
  }

  for(string v: completion) {
    status[v] -= 1;
  }

  for (auto it = status.begin(); it != status.end(); ++it) {
    if (it->second != 0) {
      return it->first;
    }
  }
  return "";
}

int main() {
  cout << "42576 - 완주하지 못한 선수" << endl;
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