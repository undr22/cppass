#include "00. leetcode.h"

// 从右上角（左下也行）开始查找，每次没找到都排除一行 / 一列
// 注意 matrix 可能为空

class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0) return false;

    int row = 0, col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
      if (target == matrix[row][col]) {
        return true;
      } else {
        target > matrix[row][col] ? ++row : --col;
      }
    }
    return false;
  }
};