#include "00. leetcode.h"

// 双指针遍历链表，注意 val 有可能不存在于链表中

class Solution {
 public:
  ListNode *deleteNode(ListNode *head, int val) {
    if (head == nullptr) return nullptr;
    if (head->val == val) return head->next;

    ListNode *prev = head, *cur = head->next;
    while (cur != nullptr && cur->val != val) {
      prev = prev->next;
      cur = cur->next;
    }
    if (cur != nullptr) {
      prev->next = cur->next;
    }
    return head;
  }
};