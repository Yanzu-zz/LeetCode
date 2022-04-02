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

class Solution19
{
private:
  int getLength(ListNode *head)
  {
    int n = 0;
    while (head)
    {
      n++;
      head = head->next;
    }
    return n;
  }

public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *dummyNode = new ListNode(0, head);
    int L = getLength(head);

    // 找到该节点
    ListNode *curr = dummyNode;
    for (int i = 1; i < L - n + 1; i++)
      curr = curr->next;

    curr->next = curr->next->next;
    ListNode *ret = dummyNode->next;
    delete dummyNode;
    return ret;
  }
};

int main(void)
{

  return 0;
}
