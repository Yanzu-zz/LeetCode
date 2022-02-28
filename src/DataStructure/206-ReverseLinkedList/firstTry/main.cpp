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

class Solution206
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = nullptr, *curr = head;
    while (curr != nullptr)
    {
      ListNode *next = curr->next;
      curr->next = prev; // 反转指针
      prev = curr;       // 保存上个指针
      curr = next;       // 后移
    }

    return prev;
  }
};

int main(void)
{

  return 0;
}
