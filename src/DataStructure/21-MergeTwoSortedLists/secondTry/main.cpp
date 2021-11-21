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

class Solution21
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;

    while (l1 != nullptr || l2 != nullptr)
    {
      // 当其中一个链表为空时，直接将结尾链接过去即可
      if (l1 == nullptr)
      {
        tail->next = l2;
        break;
      }
      if (l2 == nullptr)
      {
        tail->next = l1;
        break;
      }

      // 正常情况，就是判断大小然后链接过去
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

    return dummyHead->next;
  }
};

int main()
{

  return 0;
}