#include "00. leetcode.h"

// 使用辅助栈存储当前主栈内的最小值
// 注意新入栈的值与当前最小值相同时同样需要在辅助栈内入栈一次

class MinStack {
 public:
  MinStack() {}

  void push(int x) {
    stk.push(x);
    if (min_stk.empty() || min_stk.top() >= x) {
      min_stk.push(x);
    }
  }

  void pop() {
    if (stk.top() == min_stk.top()) min_stk.pop();
    stk.pop();
  }

  int top() { return stk.top(); }

  int min() { return min_stk.top(); }

 private:
  stack<int> stk;
  stack<int> min_stk;
};
