#include "00. leetcode.h"

// 回溯……注意题目要求是根节点到叶节点的路径

class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode *root, int target) {
    helper(root, target);

    return res;
  }

 private:
  void helper(TreeNode *root, int target) {
    if (root == nullptr) return;

    path.push_back(root->val);
    target -= root->val;
    if (target == 0 && root->left == nullptr && root->right == nullptr)
      res.push_back(path);

    helper(root->left, target);
    helper(root->right, target);

    path.pop_back();
  }

 private:
  vector<vector<int>> res;
  vector<int> path;
};