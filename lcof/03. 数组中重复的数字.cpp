#include "00. leetcode.h"

// 遍历 nums，如果当前坑里萝卜的数字和坑的数字不一样，就把它换到对应的坑里去
// 直到某一次换的时候发现要换的萝卜是一样的，即发现了重复的萝卜

class Solution {
 public:
  int findRepeatNumber(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i) {
        if (nums[i] == nums[nums[i]]) {
          return nums[i];
        } else {
          swap(nums[i], nums[nums[i]]);
        }
      }
    }
    return -1;
  }
};