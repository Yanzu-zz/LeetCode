#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution430
{
private:
  // 把它当成一个二叉树前序遍历即可
  vector<Node *> nodeList;
  void dps(Node *curr)
  {
    if (curr == nullptr) return;
    nodeList.push_back(curr);
    dps(curr->child);
    dps(curr->next);
  }

public:
  Node *flatten(Node *head)
  {
    dps(head);

    // 递归处理完后结点顺序已经解决，只需重新设置前后指针即可
    int n = nodeList.size();
    for (int i = 0; i < n; i++)
    {
      if (i > 0) nodeList[i]->prev = nodeList[i - 1];
      if (i + 1 < n) nodeList[i]->next = nodeList[i + 1];
      nodeList[i]->child = nullptr; // 题目样例返回的是没有child指针的，故要清除
    }

    return head;
  }
};

int main(void)
{

  return 0;
}
