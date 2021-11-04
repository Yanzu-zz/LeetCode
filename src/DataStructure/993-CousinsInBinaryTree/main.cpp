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

class Solution993
{
private:
  /**
   * 查找值为 val 结点的深度，并把该值的双亲结点的索引值存下来
   * root: 根结点
   * e：需要查找信息的元素值
   * step：用了多少步（深度）
   * curIndex：当前结点的索引
   * eParent：找到结点的双亲几点
   * eDepth：找到结点的深度
   */
  void findElementDepth(TreeNode *root, int e, int step, int curIndex, int &eParent, int &eDepth)
  {
    if (root == NULL)
      return;

    if (root->val == e)
    {
      eDepth = step;
      eParent = (curIndex - 1) / 2;
      return;
    }
    findElementDepth(root->left, e, step + 1, (2 * curIndex) + 1, eParent, eDepth);
    findElementDepth(root->right, e, step + 1, (2 * curIndex) + 2, eParent, eDepth);
  }

public:
  bool isCousins(TreeNode *root, int x, int y)
  {
    int xParent = 0, yParent = 0;
    int xDepth = 0, yDepth = 0;
    findElementDepth(root, x, 0, 0, xParent, xDepth);
    findElementDepth(root, y, 0, 0, yParent, yDepth);

    // 如果两个结点高度不等就说明不可能是堂兄弟结点，直接返回false
    if (xDepth != yDepth)
      return false;

    // 下面就是处理相等情况
    // 如果相等且双亲结点是同一个，那么就不是堂兄弟（是亲兄弟【笑】）
    return xParent != yParent;
  }
};

int main(void)
{

  return 0;
}
