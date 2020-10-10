#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> map1;
  unordered_map<string, int> map2 = {{"asdf", 1}, {"fdsa", 2}};

  cout << "empty: " << map1.empty() << endl;
  cout << "size: " << map1.size() << endl;
  map1["asdf"] = 1;
  map1["fdsa"] = 2;
  cout << "empty: " << map1.empty() << endl;
  cout << "size: " << map1.size() << endl;

  std::cout << "begin:";
  for (auto it = map1.begin(); it != map1.end(); ++it)
    std::cout << " " << it->first << ":" << it->second << ",";
  std::cout << std::endl;
}