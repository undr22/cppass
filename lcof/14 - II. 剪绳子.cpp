#include "00. leetcode.h"

// 贪心：数学推导可得应尽可能切成长度为 3 的绳子段
// 故依 n mod 3 分三种情况：
//   为 0 时积为 3 ^ (n/3)
//   为 1 时积为 3 ^ (n/3-1) * 4
//   为 2 时积为 3 ^ (n/3-1) * 2
// 整理代码后如下：

class Solution {
 public:
  int cuttingRope(int n) {
    if (n <= 3) return n - 1;
    if (n == 4) return n;
    long long res = 1;
    while (n > 4) {
      res *= 3;
      res %= int(1e9 + 7);
      n -= 3;
    }
    return res * n % int(1e9 + 7);
  }
};
