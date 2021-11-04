#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *head = nullptr, *tail = nullptr;
    int carry = 0;
    while (l1 || l2)
    {
      int n1 = l1 ? l1->val : 0;
      int n2 = l2 ? l2->val : 0;
      int sum = n1 + n2 + carry;
      if (!head) // 第一次相加的时候
      {
        head = tail = new ListNode(sum % 10);
      }
      else
      {
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
      }
      carry = sum / 10; // 结果只有 0和1，0表示没进位，1表示进位且加法进位只能进1，所以可以这样写

      if (l1)
      {
        l1 = l1->next;
      }
      if (l2)
      {
        l2 = l2->next;
      }
    }

    // 退出循环后还可能有进位
    if (carry > 0)
    {
      tail->next = new ListNode(carry);
    }
    return head;
  }
};

int main(void)
{

  return 0;
}
