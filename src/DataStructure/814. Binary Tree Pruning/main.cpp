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

class Solution814
{
public:
  bool dfs(TreeNode *root)
  {
    if (root == nullptr)
      return false;

    bool left = dfs(root->left);
    bool right = dfs(root->right);

    // 如果左子树没有 1 值节点，则剪枝
    if (!left)
      root->left = nullptr;
    // 右子树同理
    if (!right)
      root->right = nullptr;

    return root->val + left + right;
  }

  TreeNode *pruneTree(TreeNode *root)
  {
    bool isValid = dfs(root);
    return isValid ? root : nullptr;
  }
};

int main(void)
{

  return 0;
}
