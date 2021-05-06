#include "00. leetcode.h"

// 题目描述序列中无重复数字：故两个序列确定的进出栈顺序唯一，可使用辅助栈模拟
// 注意每次压栈后都要从未弹出序列的首部循环模拟弹栈

class Solution {
 public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> stk;
    int idx = 0;

    for (const auto num : pushed) {
      stk.push(num);
      while (!stk.empty() && popped[idx] == stk.top()) {
        stk.pop();
        ++idx;
      }
    }

    return stk.empty();
  }
};