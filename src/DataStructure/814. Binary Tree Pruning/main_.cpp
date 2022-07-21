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
  TreeNode *pruneTree(TreeNode *root)
  {
    if (!root)
      return nullptr;

    // 其实就是简单的后续遍历
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    // 这里如果子节点为 0，其实就会自动剪枝了
    // 剪枝完当前节点，那么就会递归地往上继续
    if (!root->left && !root->right && !root->val)
      return nullptr;
    // 否则正常返回
    return root;
  }
};

int main(void)
{

  return 0;
}
