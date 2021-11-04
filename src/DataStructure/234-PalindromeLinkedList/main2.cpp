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

class Solution234_2
{
private:
  ListNode *frontNode;
  bool recursivelyCheck(ListNode *curr)
  {
    if (curr != nullptr) // 意义是到了空节点就停止递归
    {
      // 先递归至（最）后面的节点
      if (!recursivelyCheck(curr->next))
        return false;

      // 然后和（最）前面的节点逐个比较
      if (frontNode->val != curr->val)
        return false;

      frontNode = frontNode->next;
    }

    return true;
  }

public:
  bool isPalindrome(ListNode *head)
  {
    frontNode = head;
    // 注意这里传递的是 head，frontNode 是用来全局对比后面的节点的
    return recursivelyCheck(head);
  }
};

int main(void)
{

  return 0;
}
