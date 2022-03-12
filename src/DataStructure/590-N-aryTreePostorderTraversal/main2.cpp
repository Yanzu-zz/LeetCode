#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

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

class Solution590_2
{
public:
  vector<int> postorder(Node *root)
  {
    vector<int> res;
    if (root == nullptr)
      return res;

    unordered_map<Node *, int> mp;
    stack<Node *> stk;
    stk.emplace(root);

    while (!stk.empty())
    {
      Node *curr = stk.top();

      // 如果当前为叶子节点或者以及遍历过的节点，这时候才 pop 处理
      if (curr->children.size() == 0 || mp[curr] != 0)
      {
        stk.pop();
        res.emplace_back(curr->val);
        continue;
        ;
      }

      for (auto child = curr->children.rbegin(); child != curr->children.rend(); child++)
        stk.emplace(*child); // 注意 stk 是存储 int 类型的，不是 Node *

      // 加完子节点后不要急着 pop 掉
      mp[curr]++;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
