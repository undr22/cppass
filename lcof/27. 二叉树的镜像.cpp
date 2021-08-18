#include "00. leetcode.h"

// 递归翻转即可

class Solution {
 public:
  TreeNode *mirrorTree(TreeNode *root) {
    if (root == nullptr) return nullptr;

    TreeNode *tmp = mirrorTree(root->left);
    root->left = mirrorTree(root->right);
    root->right = tmp;

    return root;
  }
};
