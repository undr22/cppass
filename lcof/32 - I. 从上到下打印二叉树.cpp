#include "00. leetcode.h"

// 层序遍历就行

class Solution {
 public:
  vector<int> levelOrder(TreeNode *root) {
    if (root == nullptr) return vector<int>{};

    deque<TreeNode *> level{root};
    vector<int> res;

    while (!level.empty()) {
      int size = level.size();
      while (size--) {
        res.push_back(level[0]->val);
        if (level[0]->left != nullptr) level.push_back(level[0]->left);
        if (level[0]->right != nullptr) level.push_back(level[0]->right);
        level.pop_front();
      }
    }

    return res;
  }
};