#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution116
{
public:
  Node *connect(Node *root)
  {
    if (root == nullptr)
      return nullptr;
      
    queue<Node *> qu;

    qu.emplace(root);
    while (!qu.empty())
    {
      int len = qu.size();
      for (int i = 0; i < len; i++)
      {
        Node *curr = qu.front();
        qu.pop();

        // 连接一层的节点
        if (i < len - 1)
          curr->next = qu.front();

        // 拓展下一层节点
        if (curr->left != nullptr)
          qu.emplace(curr->left);
        if (curr->right != nullptr)
          qu.emplace(curr->right);
      }
    }

    return root;
  }
};

int main(void)
{

  return 0;
}
