#include "00. leetcode.h"

// 依次把值添加进 vector 里，然后把 vector 翻转过来就好了

class Solution {
 public:
  vector<int> reversePrint(ListNode *head) {
    vector<int> res;
    while (head != nullptr) {
      res.push_back(head->val);
      head = head->next;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};