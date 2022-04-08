#include <iostream>
#include <vector>
#include <queue>

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

class Solution429
{
public:
  vector<vector<int>> levelOrder(Node *root)
  {
    vector<vector<int>> res;
    queue<Node *> qu; // 辅助队列
    if (root != nullptr)
      qu.emplace(root);

    // 开始层次遍历
    while (qu.size() > 0)
    {
      vector<int> tmp; // 当前层次数组
      int len = qu.size();

      // 控制当前层次次数
      for (int i = 0; i < len; i++)
      {
        Node *curr = qu.front();
        int n = curr->children.size();

        // 接下来就是从左到右的顺序入队 children 中的每个节点
        for (int j = 0; j < n; j++)
          qu.emplace(curr->children[j]);

        tmp.emplace_back(curr->val);
        qu.pop();
      }

      res.emplace_back(tmp);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
