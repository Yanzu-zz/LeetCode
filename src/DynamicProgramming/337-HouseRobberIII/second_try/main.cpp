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

class Solution337
{
public:
  // 本题没有记忆化搜索，所以会做大量重复运算，降低运行速度
  int rob(TreeNode *root)
  {
    if (root == null)
      return 0;

    // 偷当前节点和它的四个孙子节点的房子的钱（如果有的话）
    int hijackMoney = root->val;
    if (root->left != nullptr)
    {
      hijackMoney += rob(root->left->left);
      hijackMoney += rob(root->left->right);
    }
    if (root->right != nullptr)
    {
      hijackMoney += rob(root->right->left);
      hijackMoney += rob(root->right->right);
    }

    // 和它偷两个儿子节点房子的钱对比那个收益高
    return max(hijackMoney, rob(root->left) + rob(root->right));
  }
};

int main()
{

  return 0;
}