#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution148
{
private:
  // 合并两个有序链表
  ListNode *merge(ListNode *listA, ListNode *listB)
  {
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;

    // 链表合并操作
    while (listA != nullptr && listB != nullptr)
    {
      if (listA->val < listB->val)
      {
        tail->next = listA;
        listA = listA->next;
      }
      else
      {
        tail->next = listB;
        listB = listB->next;
      }
      tail = tail->next;
    }

    // 出来谁比较短就把长的加入 tail
    if (listA == nullptr)
      tail->next = listB;
    else if (listB == nullptr)
      tail->next = listA;

    return dummyHead->next;
  }

public:
  ListNode *sortList(ListNode *head)
  {
    return _sortList(head, nullptr);
  }

  ListNode *_sortList(ListNode *head, ListNode *tail)
  {
    if (head == nullptr)
      return nullptr;
    if (head->next == tail)
    {
      head->next = nullptr;
      return head;
    }

    // 快慢指针，目的是寻找中间结点进行递归归并排序操作
    ListNode *slow = head, *fast = head;
    while (fast != tail)
    {
      // 快指针一次走两步
      fast = fast->next;
      if (fast != tail)
        fast = fast->next;
      slow = slow->next;
    }

    // 此时 slow 位置就是当前链表中点
    ListNode *mid = slow;

    // 分割链表排序并合并
    return merge(_sortList(head, mid), _sortList(mid, tail));
  }
};

int main(void)
{

  return 0;
}
