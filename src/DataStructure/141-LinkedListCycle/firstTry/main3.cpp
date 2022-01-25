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

class Solution141
{
public:
  bool hasCycle(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return false;

    // 初始化快慢指针
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast)
    {
      // 边界条件：如果快指针能走到尽头（null）则表明没有环
      // 细节：fast位置有可能是最后一个，但下面是要走两步，故我们也要判断它的next是否合法
      if (fast == nullptr || fast->next == nullptr)
        return false;

      slow = slow->next;
      fast = fast->next->next;
    }

    return true;
  }
};

int main(void)
{

  return 0;
}
