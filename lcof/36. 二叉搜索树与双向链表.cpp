#include "00. leetcode.h"

// special struct for No. 36

struct Node {
  int val;
  Node *left;
  Node *right;

  Node() {}
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *lhs, Node *rhs) : val(x), left(lhs), right(rhs) {}
};

// 本质上就是中序遍历，使用前置节点来把指针指好就好

class Solution {
 public:
  Node *treeToDoublyList(Node *root) {
    if (root == nullptr) return nullptr;

    pre = nullptr;
    helper(root);

    head->left = pre;
    pre->right = head;

    return head;
  }

 private:
  void helper(Node *cur) {
    if (cur == nullptr) return;

    helper(cur->left);
    pre == nullptr ? head = cur : pre->right = cur;
    cur->left = pre;
    pre = cur;
    helper(cur->right);
  }

 private:
  Node *head;
  Node *pre;
};