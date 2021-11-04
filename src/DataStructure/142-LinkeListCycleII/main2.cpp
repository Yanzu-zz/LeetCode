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
    while (head)
    {
      // 堆的地址从低到高，LeetCode的链表内存是顺序申请的，如果有环，head->next一定小于或等于head
      if (!less<ListNode *>()(head, head->next))
        return head->next;

      head = head->next;
    }

    return nullptr;
  }
};

int main(void)
{

  return 0;
}
