#include "00. leetcode.h"

// 双指针……

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) return nullptr;

    ListNode *prev = nullptr, *cur = head, *next = nullptr;
    while (cur != nullptr) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
};