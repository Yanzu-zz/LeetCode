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

class Solution513
{
public:
  int findBottomLeftValue(TreeNode *root)
  {
    int res = root->val, maxLevel = 1, currLevel = 1;
    queue<TreeNode *> qu; // 用队列来模拟系统栈
    qu.emplace(root);

    // 开始 BFS
    while (!qu.empty())
    {
      // 这里就是多了个层级
      if (currLevel > maxLevel)
      {
        maxLevel = currLevel;
        res = qu.front()->val;
      }

      // 正常 层序遍历
      int len = qu.size();
      for (int i = 0; i < len; i++)
      {
        TreeNode *front = qu.front();
        qu.pop();

        if (front->left != nullptr)
          qu.emplace(front->left);
        if (front->right != nullptr)
          qu.emplace(front->right);
      }

      currLevel++;
    }

    return res;
  }
};

int main()
{

  return 0;
}