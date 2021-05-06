#include "00. leetcode.h"

// 斐波那契数列问题，注意 n 为 0 时跳法算一种

class Solution {
 public:
  int numWays(int n) {
    if (n == 0 || n == 1) return 1;

    int a = 1, b = 1, mod = 1e9 + 7;
    while (n > 1) {
      a = (a + b) % mod;
      swap(a, b);
      --n;
    }
    return b;
  }
};