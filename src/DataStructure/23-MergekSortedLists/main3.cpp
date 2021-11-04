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

class Solution23_3
{
private:
  // 21题，合并两个链表
  ListNode *metgeTwoLists(ListNode *a, ListNode *b)
  {
    if ((!a) || (!b))
      return a ? a : b;

    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;

    while (a && b)
    {
      if (a->val < b->val)
      {
        tail->next = a;
        a = a->next;
      }
      else
      {
        tail->next = b;
        b = b->next;
      }

      tail = tail->next;
    }

    tail->next = (a ? a : b);
    ListNode *ret = dummyHead->next;
    delete dummyHead;
    return ret;
  }

  // 归并地合并链表
  ListNode *merge(vector<ListNode *> &lists, int left, int right)
  {
    if (left == right)
      return lists[left];
    else if (left > right)
      return nullptr;

    int mid = left + (right - left) / 2;
    return metgeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    return merge(lists, 0, lists.size() - 1);
  }
};

int main(void)
{

  return 0;
}
