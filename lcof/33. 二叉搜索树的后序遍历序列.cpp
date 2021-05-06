#include "00. leetcode.h"

// 从左至右遍历找到第一个大于根节点的节点，作为右子树的根节点
//   验证右子树的节点是否都大于根节点
// 递归验证子树
// 另有时间复杂度更低的算法

class Solution {
 public:
  bool verifyPostorder(vector<int> &postorder) {
    return helper(postorder, 0, postorder.size() - 1);
  }

 private:
  bool helper(vector<int> &postorder, int left, int root) {
    if (left >= root) return true;

    int right = left;
    while (postorder[right] < postorder[root]) {
      ++right;
    }
    for (int i = right; i < root; ++i) {
      if (postorder[i] < postorder[root]) return false;
    }
    return helper(postorder, left, right - 1) &&
           helper(postorder, right, root - 1);
  }
};