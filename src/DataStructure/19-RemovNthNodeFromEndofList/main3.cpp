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

class Solution19_3
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *dummy = new ListNode(0, head);
    ListNode *fast = head, *slow = dummy;
    // 快指针先走 n 步
    for (int i = 0; i < n; i++)
      fast = fast->next;

    // 之后就一起走
    while (fast)
    {
      fast = fast->next;
      slow = slow->next;
    }

    // 然后 慢指针 就到了需要被删除结点的前驱结点处
    slow->next = slow->next->next;
    ListNode *ret = dummy->next;
    delete dummy;
    return ret;
  }
};

int main(void)
{

  return 0;
}
