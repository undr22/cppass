#include "00. leetcode.h"

// 注意要在循环内而非返回时取模，否则可能发生溢出

class Solution {
 public:
  int fib(int n) {
    if (n == 0 || n == 1) return n;

    int a = 0, b = 1, mod = 1e9 + 7;
    while (n > 1) {
      a = (a + b) % mod;
      swap(a, b);
      --n;
    }
    return b;
  }
};
