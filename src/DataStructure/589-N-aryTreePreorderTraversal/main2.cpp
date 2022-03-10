#include <iostream>
#include <vector>
#include <stack>

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
public:
  vector<int> preorder(Node *root)
  {
    vector<int> res;
    if (root == nullptr)
      return res;

    stack<Node *> stk; // 存储节点辅助栈
    stk.push(root);

    while (!stk.empty())
    {
      // 获取当前节点
      Node *curr = stk.top();
      // 接着就是当前元素出栈，不然后面加入新的元素后栈顶就不是这个元素了
      stk.pop();

      // 前序遍历先将需要做的动作完成，这里就是加入返回结果数组
      res.emplace_back(curr->val);

      // 接着就是从右到左加入节点
      int len = curr->children.size();
      for (int i = len - 1; i >= 0; i--)
        stk.push(curr->children[i]);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
