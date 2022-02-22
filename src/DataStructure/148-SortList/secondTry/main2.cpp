#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution148
{
public:
  ListNode *sortList(ListNode *head)
  {
    vector<int> arr;
    ListNode *start = head;

    // 先将链表元素加入 vector
    while (start != nullptr)
    {
      arr.emplace_back(start->val);
      start = start->next;
    }

    // 接着对 vector 排序
    sort(arr.begin(), arr.end());

    // 然后再将元素转换回链表形式
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;

    for (int num : arr)
    {
      tail->next = new ListNode(num);
      tail = tail->next;
    }

    return dummyHead->next;
  }
};

int main(void)
{

  return 0;
}
