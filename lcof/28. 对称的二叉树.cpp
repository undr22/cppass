#include "00. leetcode.h"

// 递归比较即可：空树为对称
//   如果当前节点的左右子节点对称，则继续比较左左和右右、左右和右左

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;

    return helper(root->left, root->right);
  }

 private:
  bool helper(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr || left->val != right->val)
      return false;
    return helper(left->left, right->right) && helper(left->right, right->left);
  }
};