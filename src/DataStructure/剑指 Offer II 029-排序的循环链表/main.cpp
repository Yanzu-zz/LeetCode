#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int val;
  Node *next;

  Node() {}

  Node(int _val)
  {
    val = _val;
    next = NULL;
  }

  Node(int _val, Node *_next)
  {
    val = _val;
    next = _next;
  }
};

class Solution
{
public:
  Node *insert(Node *head, int insertVal)
  {
    Node *node = new Node(insertVal);

    // 分三种情况

    // 空
    if (head == nullptr)
    {
      node->next = node;
      return node;
    }
    // 只有一个元素
    if (head->next == head)
    {
      // make loop linked list
      head->next = node;
      node->next = head;
      return head;
    }

    // 否则就循环一遍链表，找到对应的位置
    Node *curr = head, *next = head->next;
    while (next != head)
    {
      // 这里是找到了非递减条件下的 insertval 可以插入的位置（非边界）
      if (insertVal >= curr->val && insertVal <= next->val)
        break;

      // 到了链表末尾（不是 next 快循环一圈）
      if (curr->val > next->val)
        // 自己琢磨一下
        if (insertVal > curr->val || insertVal < next->val)
          break;

      // 到下个位置
      curr = curr->next;
      next = next->next;
    }
    // 添加新节点
    curr->next = node;
    node->next = next;

    return head;
  }
};

int main()
{

  return 0;
}