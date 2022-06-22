#include <iostream>
#include <vector>

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

class Solution513
{
public:
  int res = 0, maxLevel = 1;
  void preorder(TreeNode *curr, int level)
  {
    if (curr == nullptr)
      return;

    // 记录新的最大的层次
    if (level > maxLevel)
    {
      maxLevel = level;
      res = curr->val;
    }

    // 然后继续先序遍历
    preorder(curr->left, level + 1);
    preorder(curr->right, level + 1);
  }

  int findBottomLeftValue(TreeNode *root)
  {
    res = root->val;
    preorder(root, 1);
    return res;
  }
};

int main()
{

  return 0;
}