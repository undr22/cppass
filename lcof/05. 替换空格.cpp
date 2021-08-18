#include "00. leetcode.h"

// 按规则新构建一个 string 就完了

class Solution {
 public:
  string replaceSpace(string s) {
    string res;
    for (const auto c : s) {
      c == ' ' ? res += "%20" : res += c;
    }
    return res;
  }
};
