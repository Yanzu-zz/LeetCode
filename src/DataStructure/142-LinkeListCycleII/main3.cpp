#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution142
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *slow = head, *fast = head; // 注意这里的快指针是头指针位置
    while (fast != nullptr)
    {
      slow = slow->next;
      // 快指针要跳2个位置，这里判断防止异常
      if (fast->next == nullptr)
        return nullptr;
      fast = fast->next->next;

      // 当快慢指针相遇后，说明有环
      // 此时我们按照笔记上推导出来的公式：从相遇点到入环点的距离加上 n-1 圈的环长，恰好等于从链表头部到入环点的距离
      if (fast == slow)
      {
        ListNode *ptr = head;
        while (ptr != slow)
        {
          ptr = ptr->next;
          slow = slow->next;
        }
        return ptr;
      }
    }

    return nullptr;
  }
};

int main(void)
{

  return 0;
}
