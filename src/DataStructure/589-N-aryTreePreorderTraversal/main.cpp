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

class Solution589
{
private:
  vector<int> res;
  void _preorder(Node *curr)
  {
    if (curr == nullptr)
      return;

    // 前序遍历先把元素加入返回结果数组
    res.emplace_back(curr->val);
    // 接着就是开个循环从左到右继续前序遍历
    int len = curr->children.size();
    for (int i = 0; i < len; i++)
      _preorder(curr->children[i]);
  }

public:
  vector<int> preorder(Node *root)
  {
    _preorder(root);
    return res;
  }
};

int main(void)
{

  return 0;
}
