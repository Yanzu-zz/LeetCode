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
  // 递推翻转链表
  ListNode *reverseList(ListNode *head)
  {
    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr)
    {
      // 关键就是这个保存下个节点的变量
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }
};

int main(void)
{

  return 0;
}
