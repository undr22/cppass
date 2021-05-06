#include "00. leetcode.h"

// 字符串遵循模式 A[.[B]][e|EC] 或 .B[e|EC]，其中：
//   A 为数值的整数部分
//   B 紧跟着小数点，为数值的小数部分
//   C 紧跟着 e 或 E，为数值的指数部分
// A 部分并非必需，但如果一个数没有整数部分，其小数部分不能为空
// A、B、C 都是 0-9 的数位串，但 A、C 可能以 + 或 - 开头，B 不能
//
// 首先移除字符串首尾的空格
// 然后从头开始扫描字符串，依以上规则判断，具体实现如代码所示
// 注意将迭代器传递给 isUnsigned 或 isInt 函数时需要传引用

class Solution {
 public:
  bool isNumber(string s) {
    if (s.empty()) return false;

    removeLeadingAndTrailingSpace(s);

    string::const_iterator it = s.cbegin();
    bool is_number = isInt(it, s);
    if (*it == '.') {
      ++it;
      is_number = isUnsigned(it, s) || is_number;
    }
    if (*it == 'E' || *it == 'e') {
      ++it;
      is_number = is_number && isInt(it, s);
    }
    return is_number && (it == s.cend());
  }

 private:
  void removeLeadingAndTrailingSpace(string &s) {
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
  }

  bool isUnsigned(string::const_iterator &it, const string &s) {
    auto before = it;
    while (it != s.cend() && *it >= '0' && *it <= '9') {
      ++it;
    }
    return it > before;
  }

  bool isInt(string::const_iterator &it, const string &s) {
    if (*it == '+' || *it == '-') {
      ++it;
    }
    return isUnsigned(it, s);
  }
};