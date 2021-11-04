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

class Solution226
{
public:
  TreeNode *invertTree(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr;

    // 这里必须要保存下来，不能直接用 root->right = invertTree(root->left) 这种写法，这样会破坏原本的右子树递归
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};

int main(void)
{

  return 0;
}
