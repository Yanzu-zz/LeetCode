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

class Solution965
{
public:
  bool isUnivalTree(TreeNode *root)
  {
    if (root == nullptr)
      return false;

    int uniVal = root->val;
    return inorder(root, uniVal);
  }

  bool inorder(TreeNode *curr, int &val)
  {
    if (curr == nullptr)
      return true;

    if (curr->val != val)
      return false;

    // 继续遍历左右子树
    bool left = inorder(curr->left, val);
    bool right = inorder(curr->right, val);
    return left && right;
  }
};

int main(void)
{

  return 0;
}
