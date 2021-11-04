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

class Solution101
{
private:
  bool dfs(TreeNode *left, TreeNode *right)
  {
    // 边界条件
    if (left == nullptr && right == nullptr)
      return true;
    if (left == nullptr || right == nullptr || left->val != right->val)
      return false;

    // 没到边界的话就继续对比
    return dfs(left->left, right->right) && dfs(left->right, right->left);
  }

public:
  bool isSymmetric(TreeNode *root)
  {
    if (root == nullptr)
      return false;

    return dfs(root->left, root->right);
  }
};

int main(void)
{

  return 0;
}
