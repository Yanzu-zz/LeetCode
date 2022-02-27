#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution160
{
public:
  // 走到尽头时不见你，于是走你来时的路，等到相遇才发现，你也走过我来时的路
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    ListNode *pa = headA, *pb = headB;

    while (pa != pb)
    {
      pa = pa == nullptr ? headB : pa->next;
      pb = pb == nullptr ? headA : pb->next;
    }

    return pa;
  }
};

int main(void)
{

  return 0;
}
