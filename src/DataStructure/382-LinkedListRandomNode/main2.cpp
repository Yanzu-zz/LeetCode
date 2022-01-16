#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution382_2
{
private:
  vector<ListNode *> arr;

public:
  Solution382_2(ListNode *head)
  {
    // 将链表元素都加进数组中
    for (auto node = head; node != nullptr; node = node->next)
      arr.emplace_back(node);
  }

  int getRandom()
  {
    // 随机化取值
    return this->arr[rand() % arr.size()]->val;
  }
};

int main(void)
{

  return 0;
}
