#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution141_2
{
public:
  bool hasCycle(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return false;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
      // 如果快慢指针相遇，则表明有环
      if (fast == slow)
        return true;

      // 否则快指针前进两步，慢指针前进一步
      fast = fast->next->next;
      slow = slow->next;
    }

    return false;
  }
};

int main(void)
{

  return 0;
}
