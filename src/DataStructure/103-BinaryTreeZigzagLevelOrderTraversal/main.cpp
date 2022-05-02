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

class Solution103
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    if (root == nullptr)
      return res;

    // 辅助队列
    queue<TreeNode *> q;
    q.emplace(root);

    // 是否需要翻转数组
    bool flag = false;
    while (!q.empty())
    {
      // 当前层次的节点数量
      int len = q.size();
      vector<int> cur;
      for (int i = 0; i < len; i++)
      {
        TreeNode *tmp = q.front();
        q.pop();
        if (tmp == nullptr)
          continue;

        // 正常层序遍历
        q.emplace(tmp->left);
        q.emplace(tmp->right);

        // 保存当前节点结果
        cur.emplace_back(tmp->val);
      }

      if (flag)
      {
        // 翻转数组
        int l = 0, r = cur.size() - 1;
        while (l < r)
        {
          int num = cur[l];
          cur[l++] = cur[r];
          cur[r--] = num;
        }
      }

      flag = !flag;
      if (cur.size() > 0)
        res.emplace_back(cur);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
