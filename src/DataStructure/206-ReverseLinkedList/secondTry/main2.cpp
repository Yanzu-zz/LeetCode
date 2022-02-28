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

class Solution206_2
{
private:
  ListNode *res;
  void _reverseList(ListNode *curr, ListNode *prev)
  {
    if (curr == nullptr)
      return;

    // 保存下个节点信息
    ListNode *next = curr->next;
    curr->next = prev;
    res = curr;

    // 继续下一轮
    _reverseList(next, curr);
  }

public:
  // 递推翻转链表
  ListNode *reverseList(ListNode *head)
  {
    _reverseList(head, nullptr);
    return res;
  }
};

int main(void)
{

  return 0;
}
