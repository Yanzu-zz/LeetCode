#include <iostream>
#include <vector>
#include <queue>

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

class Solution1302
{
public:
  int deepestLeavesSum(TreeNode *root)
  {
    int res = 0;
    queue<TreeNode *> qu;
    qu.emplace(root);

    // 每次 res 都重置为当前层数的节点值之和，到最后一次自然就是 deepest leaves sum 了
    while (!qu.empty())
    {
      int len = qu.size();
      res = 0;
      for (int i = 0; i < len; i++)
      {
        TreeNode *curr = qu.front();
        qu.pop();

        // 求和
        res += curr->val;

        // 加入子节点
        if (curr->left != nullptr)
          qu.emplace(curr->left);
        if (curr->right != nullptr)
          qu.emplace(curr->right);
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
