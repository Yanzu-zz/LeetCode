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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;

    // 这里的思路与 21题 一致，不过代码实现不一样，这里优化了下
    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        tail->next = l1;
        l1 = l1->next;
      }
      else
      {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    tail->next = (l1 == nullptr ? l2 : l1);
    return dummyHead->next;
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    int n = lists.size();
    if (n == 0)
      return nullptr;

    ListNode *res = lists[0];
    // 顺序合并每个链表即可
    for (int i = 1; i < n; i++)
      res = mergeTwoLists(res, lists[i]);

    return res;
  }
};

int main()
{

  return 0;
}