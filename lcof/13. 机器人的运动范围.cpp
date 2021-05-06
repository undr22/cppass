#include "00. leetcode.h"

// dfs，终止条件是索引越界或已标记过或移动不合题意
// 注意由于是从左上角开始，故只向右或向下即可

class Solution {
 public:
  int movingCount(int m, int n, int k) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return dfs(0, 0, visited, m, n, k);
  }

 private:
  int digitSum(int i, int j) {
    int sum = 0;
    while (i != 0) {
      sum += i % 10;
      i /= 10;
    }
    while (j != 0) {
      sum += j % 10;
      j /= 10;
    }
    return sum;
  }

  int dfs(int i, int j, vector<vector<bool>> &visited, int m, int n, int k) {
    if (i == m || j == n || visited[i][j] || digitSum(i, j) > k) return 0;

    visited[i][j] = true;
    return 1 + dfs(i + 1, j, visited, m, n, k) +
           dfs(i, j + 1, visited, m, n, k);
  }
};