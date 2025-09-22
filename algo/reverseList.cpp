#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *prev = NULL;
    while (head) {
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
  ListNode *reverseListRec(ListNode *head) {
    if (!head)
      return head;
    ListNode *newHead = head;
    if (head->next) {
      newHead = reverseListRec(head->next);
      head->next->next = head;
    }
    head->next = NULL;
    return newHead;
  }
};

int main(void) {
  Solution sl;
  ListNode d(3);
  ListNode c(2, &d);
  ListNode b(1, &c);
  ListNode a(0, &b);

  ListNode *head = sl.reverseListRec(&a);
  while (head) {
    cout << head->val << endl;
    head = head->next;
  }
}
