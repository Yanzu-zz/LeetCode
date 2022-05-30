#include <iostream>

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

class Solution1022
{
public:
  int dfs(TreeNode *curr, int val)
  {
    if (curr == nullptr)
      return 0;

    // 有新的节点就 左移一位+当前节点值（都是0和1，故可以这样做）
    val = val << 1 | curr->val;
    if (curr->left == nullptr && curr->right == nullptr)
      return val;

    return dfs(curr->left, val) + dfs(curr->right, val);
  }

  int sumRootToLeaf(TreeNode *root)
  {
    return dfs(root, 0);
  }
};

int main()
{

  return 0;
}