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

class Solution2_1
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    int carry = 0; // 进位判断变量
    ListNode *head = nullptr, *tail = nullptr;

    // 链表可能会不等长，故只要有一个还没到终点就继续
    while (l1 != nullptr || l2 != nullptr)
    {
      // 计算当前位置两个节点的何和值
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry; // 加上进位（如果有）
      carry = sum / 10;                                          // 计算当前是否有进位

      if (head == nullptr) // 首个节点需要这样，后面就是正常
      {
        head = tail = new ListNode(sum % 10);
      }
      else
      {
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
      }

      if (l1 != nullptr)
        l1 = l1->next;
      if (l2 != nullptr)
        l2 = l2->next;
    }

    // 退出循环后还可能有进位
    if (carry > 0)
      tail->next = new ListNode(carry);

    return head;
  }
};

int main()
{

  return 0;
}