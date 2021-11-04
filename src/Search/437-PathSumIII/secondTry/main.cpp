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

class Solution437
{
private:
  int backTrack(TreeNode *root, int targetSum)
  {
    if (!root)
      return 0;

    // 看看 当前节点的值（也可能加上上面节点的值） 能否符合 targetSum
    int res = 0;
    if (root->val == targetSum)
      res++;

    res += backTrack(root->left, targetSum - root->val);
    res += backTrack(root->right, targetSum - root->val);
    return res;
  }

public:
  int pathSum(TreeNode *root, int targetSum)
  {
    if (!root)
      return 0;

    // 先试试选择根结点做为一个路径
    int res = backTrack(root, targetSum);
    
    // 然后再试 不选择根结点做为一个路径 的情况
    res += pathSum(root->left, targetSum);
    res += pathSum(root->right, targetSum);

    return res;
  }
};

int main()
{

  return 0;
}