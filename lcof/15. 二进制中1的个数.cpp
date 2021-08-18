#include "00. leetcode.h"

// n - 1：最右位的 1 变成 0，此位右边的 0 都变成 1
// 故 n &= (n - 1) 可消去最右位的 1

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
      n &= (n - 1);
      ++count;
    }
    return count;
  }
};
