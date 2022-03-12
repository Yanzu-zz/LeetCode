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

class Solution590
{
private:
  vector<int> res;
  void _postorder(Node *curr)
  {
    if (curr == nullptr)
      return;

    for (auto child : curr->children)
      _postorder(child);
    // 后续遍历
    res.emplace_back(curr->val);
  }

public:
  vector<int> postorder(Node *root)
  {
    _postorder(root);

    return res;
  }
};

int main(void)
{

  return 0;
}
