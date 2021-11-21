#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
public:
  int maxDepth(Node *root)
  {
    if (root == nullptr)
      return 0;

    int res = 0;
    // 递归寻找最大深度
    for (const auto &node : root->children)
      res = max(res, maxDepth(node));

    // 返回当前节点的字节点深度 + 自身1的深度即可
    return res + 1;
  }
};

int main()
{

  return 0;
}