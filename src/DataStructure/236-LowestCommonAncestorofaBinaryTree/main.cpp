#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution236
{
private:
  int P, Q;

  // 递归寻找 LCA
  TreeNode *_lowestCommonAncestor(TreeNode *curr)
  {
    // 边界条件，这样写即使传入的是 null 指针也能返回 nullptr
    if (curr == nullptr)
      return nullptr;

    // 判断当前节点是否是 PQ 节点
    if (curr->val == P || curr->val == Q)
      return curr;

    // 当前节点不是则在左右子树上重复查找 p q 操作
    TreeNode *left = _lowestCommonAncestor(curr->left);
    TreeNode *right = _lowestCommonAncestor(curr->right);

    /**
     * 此时若left为空，那最终结果只要看right；若right为空，那最终结果只要看left。
     * 原因是题目说了一定有两个待查找结点，若单侧树为空则表示另一个子结点一定在非空单侧子树的下面，
     * 故我们直接返回这个非空单侧子树即可。
     * 如果left 和right 都非空，因为只给了p和g两个结点，都非空，说明一边一个，因此 root是他们的最近公共祖先
     */
    if (left == nullptr)
      return right;
    else if (right == nullptr)
      return left;
    else
      return curr;

    // 没找到就返回空指针
    return nullptr;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    P = p->val;
    Q = q->val;

    return _lowestCommonAncestor(root);
  }
};

int main(void)
{

  return 0;
}
