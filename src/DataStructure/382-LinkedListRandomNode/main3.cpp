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

class Solution382_3
{
private:
  ListNode *head;

public:
  Solution382_3(ListNode *head)
  {
    this->head = head;
  }

  int getRandom()
  {
    int i = 1, res = 0;
    // 水塘抽样算法
    for (auto node = this->head; node != nullptr; node = node->next)
    {
      if (rand() % i == 0)
        res = node->val;
      i++;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
