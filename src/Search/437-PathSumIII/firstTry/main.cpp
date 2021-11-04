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

class Solution437
{
private:
  int ret = 0, goalVal;

  void dfs1(TreeNode *root)
  {
    if (root == nullptr)
      return;
    dfs2(root, root->val); // 带之前节点数据继续向下
    dfs1(root->left);      // 只是单纯的向下遍历，然后到视子结点为根结点向下遍历
    dfs1(root->right);     // 同上
  }

  void dfs2(TreeNode *root, int val)
  {
    if (val == goalVal)
      ret++;
    if (root->left != nullptr)
      dfs2(root->left, val + root->left->val);
    if (root->right != nullptr)
      dfs2(root->right, val + root->right->val);
  }

public:
  int pathSum(TreeNode *root, int targetSum)
  {
    goalVal = targetSum;
    dfs1(root);

    return ret;
  }
};

int main(void)
{

  return 0;
}
