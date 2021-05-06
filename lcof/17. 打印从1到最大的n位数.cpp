#include "00. leetcode.h"

// 注意本题要求返回 vector<int>，事实上无需考虑大数越界问题

class Solution {
 public:
  vector<int> printNumbers(int n) {
    vector<int> res;
    string number(n, '0');
    helper(res, number, 0, n);
    return res;
  }

 private:
  void helper(vector<int> &res, string &number, int idx, int length) {
    if (idx == length) {
      fakePrint(res, number);
      return;
    }
    for (int i = 0; i < 10; ++i) {
      number[idx] = '0' + i;
      helper(res, number, idx + 1, length);
    }
  }

  void fakePrint(vector<int> &res, const string str) {
    int num = 0;
    for (const auto c : str) {
      num *= 10;
      num += (c - '0');
    }
    if (num != 0) res.push_back(num);
  }
};