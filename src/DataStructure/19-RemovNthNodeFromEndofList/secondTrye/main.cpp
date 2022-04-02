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

class Solution19
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *fast = dummyHead, *slow = dummyHead;

    // 题目保证了 n <= list.size()，所以最多 fast 就变成 List 的最后一个元素
    while (n--)
      fast = fast->next;

    while (fast->next != nullptr)
    {
      fast = fast->next;
      slow = slow->next;
    }

    // 循环结束 slow 就到了倒数第 n+1 个链表元素
    slow->next = slow->next->next;

    return dummyHead->next;
  }
};

int main(void)
{

  return 0;
}
