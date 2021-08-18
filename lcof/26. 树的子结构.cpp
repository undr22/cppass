#include "00. leetcode.h"

// 遍历树 A，并以每个节点为根节点判断是否包含树 B

class Solution {
 public:
  bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (A == nullptr || B == nullptr) return false;
    return helper(A, B) || isSubStructure(A->left, B) ||
           isSubStructure(A->right, B);
  }

 private:
  bool helper(TreeNode *A, TreeNode *B) {
    if (B == nullptr) return true;
    if (A == nullptr || A->val != B->val) return false;
    return helper(A->left, B->left) && helper(A->right, B->right);
  }
};
