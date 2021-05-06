#include "00. leetcode.h"

// 动态规划……首先 dp[i][j] 代表 s 的前 i 个字符可以和 p 的前 j 个字符匹配
// 故 dp 的大小为 (s.size()+1) * (p.size()+1)
//
// 状态转移：考虑 dp[i][j] 何时为 true：
//   当 p[j-1] == '*' 时：
//     - dp[i][j-2] == true
//       即 p[j-1] 处的 * 匹配 p[j-2] 处的字符 0 次
//     - 或 dp[i-1][j]==true && s[i-1]==p[j-2]
//       即额外匹配 p[j-2] 处的字符 1 次
//     - 或 dp[i-1][j]==true && p[j-2]=='.'
//       即匹配一次 .
//   当 p[j-1] != '*' 时：
//     - dp[i-1][j-1]==true && s[i-1]==p[j-1]
//       即前面的匹配，新对比的字符也一样
//     - dp[i-1][j-1]==true && p[j-1]=='.'
//       即前面的匹配，新对比的字符中 p[j-1] 是个 .
//
// 初始化：显然 dp[0][0] 为 true
//   显然 dp[i][0] 全为 flase，其中 0 < i < row
//   关于 dp[0][j]：仅有 j 为偶数、dp[0][j-2] 为 true 且 p[j-1] 为 * 时，dp[0][j]才为 true
//     于是有：dp[0][j] = dp[0][j-2] && p[j-1]=='*'，其中 2 <= j < col
//
// 返回 dp[row-1][col-1] 即可

class Solution {
 public:
  bool isMatch(string s, string p) {
    int row = s.size() + 1, col = p.size() + 1;
    vector<vector<bool>> dp(row, vector<bool>(col, false));
    dp[0][0] = true;
    for (int j = 2; j < col; j += 2) {
      dp[0][j] = dp[0][j - 2] && (p[j - 1] == '*');
    }
    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < col; ++j) {
        dp[i][j] =
            p[j - 1] == '*'
                ? dp[i][j - 2] ||
                      dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                : dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
      }
    }
    return dp[row - 1][col - 1];
  }
};