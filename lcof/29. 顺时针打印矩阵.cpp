#include "00. leetcode.h"

// 从左上角向右遍历，（碰到边界后）依次向下、向左、向上并收窄边界
//   收窄和判断边界写在一起了

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty()) return vector<int>{};

    vector<int> res{matrix[0][0]};

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    int r = 0, c = 0;

    while (true) {
      while (c < right) {
        res.push_back(matrix[r][++c]);
      }
      if (++top > bottom) break;

      while (r < bottom) {
        res.push_back(matrix[++r][c]);
      }
      if (--right < left) break;

      while (c > left) {
        res.push_back(matrix[r][--c]);
      }
      if (--bottom < top) break;

      while (r > top) {
        res.push_back(matrix[--r][c]);
      }
      if (++left > right) break;
    }

    return res;
  }
};
