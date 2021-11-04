#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution141
{
public:
  bool hasCycle(ListNode *head)
  {
    unordered_set<ListNode *> set;
    while (head != nullptr)
    {
      // if (set.find(head) != set.end())
      if(set.count(head))
        return true;

      set.insert(head);
      head = head->next;
    }

    return false;
  }
};

int main(void)
{

  return 0;
}
