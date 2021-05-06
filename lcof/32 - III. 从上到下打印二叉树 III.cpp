#include "00. leetcode.h"

// 又是层序遍历

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) return vector<vector<int>>{};

    deque<TreeNode *> level{root};
    vector<vector<int>> res;
    int count = 1;

    while (!level.empty()) {
      int size = level.size();
      vector<int> tmp;
      while (size--) {
        tmp.push_back(level[0]->val);
        if (level[0]->left != nullptr) level.push_back(level[0]->left);
        if (level[0]->right != nullptr) level.push_back(level[0]->right);
        level.pop_front();
      }
      if (count++ % 2 == 0) reverse(tmp.begin(), tmp.end());
      res.push_back(tmp);
    }

    return res;
  }
};