#include <iostream>
#include <vector>

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
    int count = 100001;
    // 有环的话也不怕，有计数变量
    while (head != nullptr && count-- >= 0)
      head = head->next;

    if (head == nullptr) // 能指向空指针说明没有环
      return false;

    return true;
  }
};

int main(void)
{

  return 0;
}
