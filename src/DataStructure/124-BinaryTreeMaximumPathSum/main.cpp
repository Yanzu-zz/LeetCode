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

class Solution124
{
private:
  int maxSum = INT_MIN;

  int _maxPathSum(TreeNode *root)
  {
    if (root == nullptr)
      return 0;

    // 计算左右子节点的最大贡献值（递归）
    // 因为节点的值可能是负数，故我们只有在值大于0时才选取
    int left = max(_maxPathSum(root->left), 0);
    int right = max(_maxPathSum(root->right), 0);

    // 然后当前节点的最大贡献值就等于 当前节点值 + 左/右子节点的最大贡献值
    int curVal = root->val + left + right;

    // 更新记录到的最大值路径和值
    maxSum = max(maxSum, curVal);

    // 然后返回 这个轮次计算到的当前节点的最大贡献值（路径和）
    // 即只能左右节点选一个
    return root->val + max(left, right);
  }

public:
  int maxPathSum(TreeNode *root)
  {
    _maxPathSum(root);
    return maxSum;
  }
};

int main(void)
{

  return 0;
}
