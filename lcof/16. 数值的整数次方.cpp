#include "00. leetcode.h"

// 快速幂，注意边界条件

class Solution {
 public:
  double myPow(double x, int n) {
    if (x == 0) return 0;
    if (x == 1 || n == 0) return 1;

    double res = 1;
    long long exp = n;
    if (n < 0) {
      x = 1 / x;
      exp *= -1;
    }
    while (exp != 0) {
      if (exp & 1 == 1) res *= x;
      x *= x;
      exp >>= 1;
    }
    return res;
  }
};
