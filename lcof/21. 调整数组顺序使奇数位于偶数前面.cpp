#include "00. leetcode.h"

// 双指针：slow 指向下一个奇数交换后的位置，fast 步进，遇到奇数则与 slow 交换

class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    vector<int>::iterator fast = nums.begin(), slow = nums.begin();
    while (fast != nums.end()) {
      if (*fast & 1) {
        swap(*fast, *slow);
        ++slow;
      }
      ++fast;
    }
    return nums;
  }
};