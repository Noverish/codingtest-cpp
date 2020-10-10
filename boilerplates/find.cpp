#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<string> words = {"red", "orange", "yellow"};
    string str = "yellow";

    auto pointer = find(words.begin(), words.end(), str);

    if (pointer == words.end()) {
        cout << "Not Found" << endl;
    } else {
        auto index = distance(words.begin(), pointer);
        cout << "index: " << index << ", ";
        cout << "value: " << *pointer << endl;
    }
}
