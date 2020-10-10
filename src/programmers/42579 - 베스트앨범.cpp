#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>
#include "../print_utils.hpp"

using namespace std;

vector<tuple<vector<string>, vector<int>>> inputs = {
  {{"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500}}
};

vector<int> outputs[] = {
  {4, 1, 3, 0}
};

bool compare(tuple<int, int> left, tuple<int, int> right){
  return get<0>(left) > get<0>(right);
}

bool compare2(tuple<int, string> left, tuple<int, string> right){
  return get<0>(left) > get<0>(right);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  unordered_map<string, vector<tuple<int, int>>> map;
  unordered_map<string, int> total;
  vector<int> answer;

  for(int i = 0; i < genres.size(); i++) {
    string genre = genres[i];
    int play = plays[i];
    
    map[genre].push_back({ play, i });
    total[genre] += play;
  }

  vector<tuple<int, string>> total2;
  for(auto pair: total) {
    total2.push_back({ pair.second, pair.first });
  }
  sort(total2.begin(), total2.end(), compare2);

  for(auto pair: total2) {
    string genre = get<1>(pair);
    vector<tuple<int, int>> arr = map.at(genre);
    sort(arr.begin(), arr.end(), compare);

    answer.push_back(get<1>(arr[0]));
    if (arr.size() > 1) {
      answer.push_back(get<1>(arr[1]));
    }
  }

  return answer;
}

int main() {
  cout << "42579 - 베스트앨범" << endl;
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