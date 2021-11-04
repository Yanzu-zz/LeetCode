#include <iostream>
#include <vector>

using namespace std;

/**
 解法一、暴力递归 - 最优子结构
    在解法一和解法二中，我们使用爷爷、两个孩子、4 个孙子来说明问题
    首先来定义这个问题的状态
    爷爷节点获取到最大的偷取的钱数呢

    首先要明确相邻的节点不能偷，也就是爷爷选择偷，儿子就不能偷了，但是孙子可以偷
    二叉树只有左右两个孩子，一个爷爷最多 2 个儿子，4 个孙子
    根据以上条件，我们可以得出单个节点的钱该怎么算
    4 个孙子偷的钱 + 爷爷的钱 VS 两个儿子偷的钱 哪个组合钱多，就当做当前节点能偷的最大钱数。这就是动态规划里面的最优子结构
 */

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
  int rob(TreeNode *root)
  {
    if (root == NULL)
      return 0;

    int money = root->val;
    // 此时这里就是我们分析的选择偷爷爷结点和 4 个孙子结点
    if (root->left != NULL) // 左子树的孙子结点
      money += (rob(root->left->left) + rob(root->left->right));
    if (root->right != NULL) // 右子树的孙子结点
      money += (rob(root->right->left) + rob(root->right->right));

    // 然后就比较偷爷爷结点+4个孙子节点的收益高还是 偷 两个儿子结点的收益高（因为不能偷相邻的结点）
    return max(money, rob(root->left) + rob(root->right));
  }
};

int main(void)
{

  return 0;
}
