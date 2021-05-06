#include "00. leetcode.h"

// 由前序遍历找到根节点，再找到根节点在中序遍历中的位置
// 计算出左右子树在遍历中的范围，递归构建
// 注意空（子）树的情况（L1 行）

class Solution {
 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int size = preorder.size();
    TreeNode *root = helper(preorder, inorder, 0, size - 1, 0, size - 1);
    return root;
  }

 private:
  TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int pre_l,
                   int pre_r, int in_l, int in_r) {
    if (pre_l > pre_r) return nullptr;  // L1

    TreeNode *cur_node = new TreeNode(preorder[pre_l]);
    int in_cur = 0;
    for (int i = in_l; i <= in_r; ++i) {
      if (inorder[i] == preorder[pre_l]) {
        in_cur = i;
      }
    }
    cur_node->left = helper(preorder, inorder, pre_l + 1, pre_r - in_r + in_cur,
                            in_l, in_cur - 1);
    cur_node->right = helper(preorder, inorder, pre_r - in_r + in_cur + 1,
                             pre_r, in_cur + 1, in_r);

    return cur_node;
  }
};