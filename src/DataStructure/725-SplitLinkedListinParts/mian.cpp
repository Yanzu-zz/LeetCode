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

class Solution725
{
public:
  vector<ListNode *> splitListToParts(ListNode *head, int k)
  {
    ListNode *curr = head;
    int n = 0, x, y;
    while (curr != nullptr) // 统计链表有多少个数
    {
      n++;
      curr = curr->next;
    }

    // 获取我们分配时需要的关键数值
    x = n % k; // x 为余数，用来控制前 x 个数组需要多添加1个元素
    y = n / k; // y 为除数，用来控制k个数组中的每个数组基础有多少个元素

    vector<ListNode *> ret(k, nullptr);
    curr = head;
    for (int i = 0; i < k && curr != nullptr; i++)
    {
      ret[i] = curr; // 将指针位置赋值
      int partSize = y + (i < x ? 1 : 0);
      for (int j = 1; j < partSize; j++)
        curr = curr->next;

      ListNode *next = curr->next;
      curr->next = nullptr;
      curr = next;
    }

    return ret;
  }
};

int main(void)
{

  return 0;
}
