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

class Solution1609
{
public:
  bool isEvenOddTree(TreeNode *root)
  {
    bool isEvenIdx = true; // 是否为偶数索引层 占位符
    queue<TreeNode *> q;
    q.emplace(root);

    // 只要队列还没空就继续检查下去
    while (!q.empty())
    {
      int count = q.size();
      TreeNode *prev = q.front();
      // 当然，一次循环只检查当前队列元素的个数的次数，这中间加进队列的元素次数不算
      while (count-- > 0)
      {
        // 下面就是验证这棵树是否符合奇偶数的定义要求了
        TreeNode *curr = q.front(); // 先拿到当前队首元素
        q.pop();

        // 是偶数层数情况
        if (isEvenIdx)
        {
          // 如果偶数层的节点值为偶数则非法
          // 偶数层要求从左到右节点的值 严格递增
          if ((curr->val % 2 == 0) || (prev != curr && curr->val <= prev->val))
            return false;
        }
        else // 奇数层情况
        {
          // 奇数层要求从左到右节点的值 严格递减
          if ((curr->val % 2 == 1) || prev != curr && curr->val >= prev->val)
            return false;
        }

        // 当前节点校验完毕后就是加入它的子节点了
        if (curr->left != nullptr)
          q.emplace(curr->left);
        if (curr->right != nullptr)
          q.emplace(curr->right);

        prev = curr; // 保存这一个节点的值以便与下个节点大小对比
      }

      isEvenIdx = !isEvenIdx; // 奇偶变换
    }

    // 如果校验都通过了则表明这棵树是一颗奇偶树
    return true;
  }
};

int main(void)
{

  return 0;
}
