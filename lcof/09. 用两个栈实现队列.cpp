#include "00. leetcode.h"

// 两个栈分别负责进出
// 注意仅当 stack_o 为空时才执行 i2o()

class CQueue {
 public:
  CQueue() {}

  void appendTail(int value) { stack_i.push(value); }

  int deleteHead() {
    if (stack_o.empty()) i2o();
    if (stack_o.empty()) {
      return -1;
    } else {
      int res = stack_o.top();
      stack_o.pop();
      return res;
    }
  }

 private:
  stack<int> stack_i;
  stack<int> stack_o;

  void i2o() {
    while (!stack_i.empty()) {
      stack_o.push(stack_i.top());
      stack_i.pop();
    }
  }
};