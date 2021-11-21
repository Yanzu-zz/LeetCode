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

class Solution23
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;
    int k = lists.size();
    if (k == 0)
      return nullptr;

    while (1)
    {
      int currMinVal = INT_MAX; // 当前循环轮次找到的最小值
      int currMinIndex = -1;    // 当前循环轮次最小值的索引
      for (int i = 0; i < k; i++)
      {
        // 当前链表空了就不理了
        if (lists[i] == nullptr)
          continue;

        if (lists[i]->val < currMinVal)
        {
          currMinVal = lists[i]->val;
          currMinIndex = i;
        }
      }

      // 一个最小值都没有的情况就是链表全部遍历完毕了，该退出循环了
      if (currMinVal == INT_MAX)
        break;

      lists[currMinIndex] = lists[currMinIndex]->next; // 每次只移动最小值处的指针
      tail->next = new ListNode(currMinVal);
      tail = tail->next;
    }

    return dummyHead->next;
  }
};

int main(void)
{

  return 0;
}
