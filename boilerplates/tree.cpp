#include "../common.hpp"

class Node {
  public:
    char ch;
    unordered_map<char, Node*> children;

    Node(char c) {
      ch = c;
    }
};

int main() {
  Node *root = new Node(' ');
  string str = "123456789";

  Node *now = root;
  for(int i = 0; i < str.length(); i++) {
    char ch = str[i];
    cout << now->ch << endl;

    Node *newNode = new Node(ch);
    now->children.emplace(ch, newNode);
    now = newNode;
  }
}
