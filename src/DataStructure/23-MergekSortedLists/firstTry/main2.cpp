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

class Solution23_2
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

public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    int n = lists.size();
    ListNode *ret = nullptr;
    for (int i = 0; i < n; i++)
      ret = metgeTwoLists(ret, lists[i]);

    return ret;
  }
};

int main(void)
{

  return 0;
}
