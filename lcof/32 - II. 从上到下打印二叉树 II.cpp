#include "00. leetcode.h"

// 还是层序遍历

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) return vector<vector<int>>{};

    deque<TreeNode *> level{root};
    vector<vector<int>> res;

    while (!level.empty()) {
      int size = level.size();
      vector<int> tmp;
      while (size--) {
        tmp.push_back(level[0]->val);
        if (level[0]->left != nullptr) level.push_back(level[0]->left);
        if (level[0]->right != nullptr) level.push_back(level[0]->right);
        level.pop_front();
      }
      res.push_back(tmp);
    }

    return res;
  }
};