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
    unordered_set<ListNode *> set;
    // 有环则返回，无则插入并且查看下个节点
    while (head != nullptr)
    {
      if (set.count(head))
        return head;

      set.insert(head);
      head = head->next;
    }

    return nullptr;
  }
};

int main(void)
{

  return 0;
}
