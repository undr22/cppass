#include "00. leetcode.h"

// 双指针：快的先走，然后一起走，返回慢的
// 注意 head 为空指针、k 为 0、k 超过链表长度三种特殊情况

class Solution {
 public:
  ListNode *getKthFromEnd(ListNode *head, int k) {
    if (head == nullptr || k == 0) return nullptr;

    ListNode *fast = head, *slow = head;
    while (k--) {
      if (fast != nullptr) {
        fast = fast->next;
      } else {
        return nullptr;
      }
    }
    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};
