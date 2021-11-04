#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
  记忆化 - 解决重复子问题构
    针对解法一种速度太慢的问题，经过分析其实现，我们发现爷爷在计算自己能偷多少钱的时候，
    同时计算了 4 个孙子能偷多少钱，也计算了 2 个儿子能偷多少钱。这样在儿子当爷爷时，
    就会产生重复计算一遍孙子节点。

    于是乎我们发现了一个动态规划的关键优化点 —— 重复子问题

    我们这一步针对重复子问题进行优化，我们在做斐波那契数列时，使用的优化方案是记忆化，
    但是之前的问题都是使用数组解决的，把每次计算的结果都存起来，下次如果再来计算，
    就从缓存中取，不再计算了，这样就保证每个数字只计算一次。
    由于二叉树不适合拿数组当缓存，我们这次使用哈希表来存储结果，TreeNode 当做 key，
    能偷的钱当做 value
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
private:
  unordered_map<TreeNode *, int> memo;

  int robInternal(TreeNode *root)
  {
    if (root == NULL)
      return 0;

    if (memo.find(root) != memo.end())
      return memo.at(root);

    int money = root->val;
    // 此时这里就是我们分析的选择偷爷爷结点和 4 个孙子结点
    if (root->left != NULL) // 左子树的孙子结点
      money += (robInternal(root->left->left) + robInternal(root->left->right));
    if (root->right != NULL) // 右子树的孙子结点
      money += (robInternal(root->right->left) + robInternal(root->right->right));

    // 然后就比较偷爷爷结点+4个孙子节点的收益高还是 偷 两个儿子结点的收益高（因为不能偷相邻的结点）
    int result = max(money, robInternal(root->left) + robInternal(root->right));
    memo.insert(make_pair(root, result));
    return result;
  }

public:
  int rob(TreeNode *root)
  {
    return robInternal(root);
  }
};

int main(void)
{

  return 0;
}
