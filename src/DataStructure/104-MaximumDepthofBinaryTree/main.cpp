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

class Solution104
{
private:
  void dfs(TreeNode *root, int curDepth, int &maxDepth)
  {
    // boundary contition
    if (root == nullptr)
    {
      maxDepth = max(maxDepth, curDepth);
      return;
    }

    dfs(root->left, curDepth + 1, maxDepth);
    dfs(root->right, curDepth + 1, maxDepth);
  }

public:
  int maxDepth(TreeNode *root)
  {
    int maxDepth = INT_MIN;

    // 因为我们是先将当前层数的值+1再判断边界条件的，若此时到了底部，按照根节点是 1 层的值传进去会多一层的值，故我们初始 curDepth 值将其置 0 即可
    dfs(root, 0, maxDepth);

    return maxDepth;
  }
};

int main(void)
{

  return 0;
}
