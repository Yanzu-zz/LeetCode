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

class Solution700
{
public:
  TreeNode *searchBST(TreeNode *root, int val)
  {
    if (root == nullptr || root->val == val)
      return root;

    // 根据 二叉搜索树 的特性来降低时间复杂度
    if (root->val > val)
      return searchBST(root->left, val);
    else
      return searchBST(root->right, val);
  }
};

int main()
{

  return 0;
}