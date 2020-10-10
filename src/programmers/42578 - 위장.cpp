#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<vector<string>>> inputs = {
  {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}},
  {{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}}
};

int outputs[] = {
  5,
  3
};

int solution(vector<vector<string>> clothes) {
  unordered_map<string, unordered_set<string>> map;

  for(vector<string> cloth: clothes) {
    string name = cloth[0];
    string type = cloth[1];

    if (map.count(type) == 0) {
      map.insert({type, {}});
    }

    map.at(type).insert(name);
  }

  int result = 1;
  for(auto pair: map) {
    result *= pair.second.size() + 1;
  }

  return result - 1;
}

int main() {
  cout << "42578 - 위장" << endl;
  for (int i = 0; i < inputs.size(); i++) {
    auto input = inputs[i];
    auto expected = outputs[i];
    auto real = solution(input);

    if(real == expected) {
      cout << "success" << endl;
    } else {
      cout << "failed" << endl;
      cout << expected << endl;
      cout << real << endl;
    }
  }
}