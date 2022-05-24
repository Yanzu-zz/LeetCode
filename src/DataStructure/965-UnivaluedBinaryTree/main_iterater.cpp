#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution965
{
public:
  bool isUnivalTree(TreeNode *root)
  {
    if (root == nullptr)
      return false;

    queue<TreeNode *> qu;
    int uniVal = root->val;
    qu.emplace(root);

    // Starting iterate the tree
    while (qu.size() > 0)
    {
      int len = qu.size();
      for (int i = 0; i < len; i++)
      {
        TreeNode *curr = qu.front();
        qu.pop();
        if (curr->val != uniVal)
          return false;

        // Go on push more node into queue
        if (curr->left != nullptr)
          qu.emplace(curr->left);
        if (curr->right != nullptr)
          qu.emplace(curr->right);
      }
    }

    return true;
  }
};

int main(void)
{

  return 0;
}
