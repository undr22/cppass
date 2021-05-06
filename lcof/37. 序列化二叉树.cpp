#include "00. leetcode.h"

// 注意题目并未要求二叉树序列化后与 leetcode 测试用例格式一致
// 用括号表示编码，递归下降解码：
//   可以这样来表示一棵二叉树：
//     空树为 X；非空为 (left_subtree)cur_val(right_subtree)
//   巴科斯范式为：T -> (T)num(T) | X
//     其中 T 代表一棵树序列化后的结果，| 表示 T 的构成为 (T)num(T) 或 X
//     即 | 左边是对 T 的递归定义，右边规定了递归终止的边界条件

class Codec {
 public:
  string serialize(TreeNode *root) {
    if (root == nullptr) return "X";

    auto l = "(" + serialize(root->left) + ")";
    auto r = "(" + serialize(root->right) + ")";
    return l + to_string(root->val) + r;
  }

  TreeNode *deserialize(string data) {
    int idx = 0;
    return parse(data, idx);
  }

 private:
  TreeNode *parse(const string &data, int &idx) {
    if (data[idx] == 'X') {
      ++idx;
      return nullptr;
    }

    TreeNode *cur = new TreeNode();
    cur->left = parseSubTree(data, idx);
    cur->val = parseInt(data, idx);
    cur->right = parseSubTree(data, idx);

    return cur;
  }

  TreeNode *parseSubTree(const string &data, int &idx) {
    ++idx;
    TreeNode *sub_tree = parse(data, idx);
    ++idx;

    return sub_tree;
  }

  int parseInt(const string &data, int &idx) {
    int val = 0, sign = 1;
    if (!isdigit(data[idx])) {
      sign = -1;
      ++idx;
    }
    while (isdigit(data[idx])) {
      val = val * 10 + data[idx++] - '0';
    }

    return sign * val;
  }
};