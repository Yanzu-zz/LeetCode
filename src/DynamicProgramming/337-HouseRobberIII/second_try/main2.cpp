#include <iostream>
#include <vector>
#include <unordered_map>

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

class Solution337_2
{
private:
  // 这个方法就是在方法一的基础上，用哈希表保存之前运算出来节点的结果，加快运算速度（记忆化搜索）
  int _rob(TreeNode *root, unordered_map<TreeNode *, int> &memo)
  {
    if (root == nullptr)
      return 0;

    // 这一步很关键，把上次运算过的节点最大值存起来，下次需要获取时直接返回即可
    if (memo[root] != 0) {
      cout << memo[root] << endl;
      return memo[root];
    }

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
    int currMaxProfit = max(hijackMoney, rob(root->left) + rob(root->right));
    pair<TreeNode *, int> tmp(root, currMaxProfit);
    memo.insert(tmp);
    return currMaxProfit;
  }

public:
  int rob(TreeNode *root)
  {
    unordered_map<TreeNode *, int> memo;
    return _rob(root, memo);
  }
};

int main()
{

  return 0;
}