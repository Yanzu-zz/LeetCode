#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution141
{
private:
  unordered_map<ListNode *, int> mp;

public:
  bool hasCycle(ListNode *head)
  {
    while (head != nullptr)
    {
      // 若又回到了之前的节点，说明有环
      if (mp[head] != 0)
        return true;

      // 哈希表记录下当前节点
      mp[head]++;
      head = head->next;
    }

    return false;
  }
};

int main(void)
{

  return 0;
}
