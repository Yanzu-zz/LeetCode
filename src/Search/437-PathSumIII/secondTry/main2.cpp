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

class Solution437
{
private:
  int res = 0;
  void dfs(TreeNode *root, int targetSum, int currSum, unordered_map<int, int> &memo)
  {
    if (!root)
      return;

    currSum += root->val;
    // 用减法来判断是否存在某个数值在树中出现
    // 比如，若哈希表中记录了 10 这个数值，当遍历到 18 时，发现哈希表中有 18 - 8 = 10，就证明当前有个路径和能达到 8
    if (memo[currSum - targetSum] != 0)
      res += memo[currSum - targetSum];
    // 记录下来
    memo[currSum] = memo[currSum] + 1;

    // 继续左右深度搜索找更多所求路径和
    dfs(root->left, targetSum, currSum, memo);
    dfs(root->left, targetSum, currSum, memo);

    // 回溯
    memo[currSum] = memo[currSum] - 1;
  }

public:
  int pathSum(TreeNode *root, int targetSum)
  {
    unordered_map<int, int> memo;
    memo[0] = 1;

    dfs(root, targetSum, 0, memo);

    return res;
  }
};

int main()
{

  return 0;
}