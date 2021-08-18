#include "00. leetcode.h"

// special struct for No. 35
struct Node {
  int val;
  Node *next;
  Node *random;

  Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

// 在原链表的各节点后插入一个相等值的新节点
// 搞定新节点的 random 指向
// 把链表拆成两个：原来的和复制的
//   注意拆分链表的时候要额外关照一下原链表的尾巴

class Solution {
 public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) return nullptr;

    Node *cur = head;
    while (cur != nullptr) {
      Node *tmp = new Node(cur->val);
      tmp->next = cur->next;
      cur->next = tmp;
      cur = tmp->next;
    }

    cur = head;
    while (cur != nullptr) {
      if (cur->random != nullptr) cur->next->random = cur->random->next;
      cur = cur->next->next;
    }

    cur = head->next;
    Node *pre = head, *res = head->next;
    while (cur->next != nullptr) {
      pre->next = cur->next;
      cur->next = cur->next->next;
      pre = pre->next;
      cur = cur->next;
    }
    pre->next = nullptr;

    return res;
  }
};
