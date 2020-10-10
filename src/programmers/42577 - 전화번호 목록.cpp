#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<string>> inputs = {
  {"119", "97674223", "1195524421"},
  {"1195524421", "97674223", "119"},
  {"123", "456", "789"},
  {"12", "123", "1235", "567", "88"}
};

int outputs[] = {
  false,
  false,
  true,
  false,
};

class Node {
  public:
    char ch;
    unordered_map<char, Node*> children;
    bool is_end;

    Node(char c) {
      ch = c;
      is_end = false;
    }
};

bool solution(vector<string> phone_book) {
  Node *root = new Node(' ');

  for(string phone: phone_book) {
    Node *now = root;
    bool generate_new = false;

    for(int i = 0; i < phone.length(); i++) {
      char ch = phone[i];

      if (now->children.count(ch)) {
        now = now->children.at(ch);
      } else {
        Node *newNode = new Node(ch);
        now->children.emplace(ch, newNode);
        now = newNode;
        generate_new = true;
      }

      // cout << generate_new << " " << now->ch << " " << phone << endl;
      if (!generate_new && now->is_end == 1) {
        return false;
      }

      if (i == phone.length() - 1) {
        now->is_end = 1;
      }
    }

    if (!generate_new) {
      return false;
    }
  }

  return true;
}

int main() {
  cout << "42577 - 전화번호 목록" << endl;
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