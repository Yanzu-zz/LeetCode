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

class Solution382
{
private:
  ListNode *head;
  int len = 0;

public:
  Solution382(ListNode *head)
  {
    this->head = head;
    for (auto node = head; node != nullptr; node = node->next)
      len++;
  }

  int getRandom()
  {
    int random = rand() % len;
    auto node = this->head;

    // 跳到对应的元素上
    while (random-- > 0)
      if (node->next != nullptr)
        node = node->next;

    return node->val;
  }
};

int main(void)
{

  return 0;
}
