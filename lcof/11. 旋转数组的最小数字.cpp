#include "00. leetcode.h"

// 二分查找：通过对比中间值和右边界值来确定舍弃的部分
// 为什么是对比右边界而不是左边界：
//   以最小值为轴，如果整个数组有序，则不存在左排序数组
//   即总能通过对比右边界来舍弃某一部分，对比左边界则不行
// 为什么要 --right：
//   中间值和右边界值相等时无法判断舍弃二分的那一部分
//   但总之总有值和右边界值相等，故舍弃右边界重新二分

class Solution {
 public:
  int minArray(vector<int> &numbers) {
    int left = 0, right = numbers.size() - 1, mid = left;
    while (left != right) {
      mid = left + (right - left) / 2;
      if (numbers[mid] < numbers[right]) {
        right = mid;
      } else if (numbers[mid] > numbers[right]) {
        left = mid + 1;
      } else {
        --right;
      }
    }
    return numbers[left];
  }
};