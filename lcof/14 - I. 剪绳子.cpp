#include "00. leetcode.h"

// 动态规划：长度为 i 的绳子在 j 处切一刀，剩下的可以切或不切
//   dp[i] = max(j * (i-j), j * dp[i-j])，遍历 1 <= j < i
// 注意 std::max 接受两个参数或一个 initializer_list

class Solution {
 public:
  int cuttingRope(int n) {
    vector<int> dp(n + 1);
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
      }
    }
    return dp[n];
  }
};
