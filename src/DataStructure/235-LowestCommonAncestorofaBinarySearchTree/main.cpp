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

class Solution235
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    /**
     *
     * 如果当前节点的值大于 pp 和 qq 的值，说明 pp 和 qq 应该在当前节点的左子树，因此将当前节点移动到它的左子节点；
     * 如果当前节点的值小于 pp 和 qq 的值，说明 pp 和 qq 应该在当前节点的右子树，因此将当前节点移动到它的右子节点；
     * 如果当前节点的值不满足上述两条要求，那么说明当前节点就是「分岔点」。此时，pp 和 qq 要么在当前节点的不同的子树中，要么其中一个就是当前节点。
     */
    while (root != nullptr)
    {
      int currVal = root->val, leftVal = p->val, rightVal = q->val;
      if (currVal < leftVal && currVal < rightVal)
        root = root->right;
      else if (currVal > leftVal && currVal > rightVal)
        root = root->left;
      else
        break;
    }

    return root;
  }
};

int main(void)
{

  return 0;
}
