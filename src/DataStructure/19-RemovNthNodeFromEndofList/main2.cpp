#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution19_2
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    stack<ListNode *> stk;
    ListNode *dummy = new ListNode(0, head);
    ListNode *curr = dummy;
    // 开始 push 元素
    while (curr)
    {
      stk.push(curr);
      curr = curr->next;
    }

    while (n--)
      stk.pop();

    curr = stk.top();
    curr->next = curr->next->next;
    ListNode *ret = dummy->next;
    delete dummy;
    return ret;
  }
};

int main(void)
{

  return 0;
}
