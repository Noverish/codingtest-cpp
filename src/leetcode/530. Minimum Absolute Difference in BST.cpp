#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode n2 = {2};
TreeNode n3 = {3, &n2, nullptr};
TreeNode n1 = {1, nullptr, &n3};

vector<TreeNode *> inputs = {
  &n1
};

int outputs[] = {
  1
};

void inorder(TreeNode *node, vector<int> &nums) {
  if (!node) return;

  inorder(node->left, nums);
  nums.push_back(node->val);
  inorder(node->right, nums);
}

int getMinimumDifference(TreeNode *root) {
  vector<int> nums;
  int minimum = INT_MAX;

  inorder(root, nums);

  for (int i = 0; i < nums.size() - 1; i++) {
    minimum = min(minimum, nums[i + 1] - nums[i]);
  }

  return minimum;
}

int main() {
  cout << "530. Minimum Absolute Difference in BST" << endl;
  for (int i = 0; i < inputs.size(); i++) {
    auto input = inputs[i];
    auto expected = outputs[i];
    auto real = getMinimumDifference(input);

    if (real == expected) {
      cout << "success" << endl;
    } else {
      cout << "failed" << endl;
      cout << expected << endl;
      cout << real << endl;
    }
  }
}