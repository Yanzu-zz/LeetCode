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

class Solution61
{
public:
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (k == 0 || head == nullptr)
      return head;

    int n = 0;
    ListNode *tail = head;

    // 寻找当前链表的尾部，并且记录链表长度
    while (tail != nullptr)
    {
      n++;

      if (tail->next == nullptr)
        break;
      tail = tail->next;
    }

    // k 可能很大，那么多出来的那部分就没用，我们 mod 一下
    k %= n;

    // 然后找到 rotate 点的前一个元素，
    // 即找到链表的第n-k个节点
    ListNode *newHead = head;
    for (int i = 0; i < n - k - 1; i++)
      newHead = newHead->next;

    // 接着更新旋转后的 头部节点
    tail->next = head;
    head = newHead->next;
    newHead->next = nullptr;

    return head;
  }
};

int main(void)
{

  return 0;
}
