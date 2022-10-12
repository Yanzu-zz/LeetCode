#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  int numComponents(ListNode *head, vector<int> &nums)
  {
    unordered_set<int> set;
    for (int num : nums)
      set.emplace(num);

    ListNode *curr = head;
    int res = 0;
    bool inSet = false;
    while (curr != nullptr)
    {
      // 每次遇到分割点就比较当前最长长度
      if (set.count(curr->val) > 0)
      {
        if (!inSet)
        {
          inSet = true;
          res++;
        }
      }
      else
      {
        inSet = false;
      }

      curr = curr->next;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
