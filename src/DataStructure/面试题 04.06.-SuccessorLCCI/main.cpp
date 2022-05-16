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

class Solution0406
{
public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
  {
    TreeNode *res = nullptr;
    TreeNode *curr = root;

    // 利用二叉搜索树的性质很容易写出这个代码
    int target = p->val;
    while (curr != nullptr)
    {
      if (curr->val > target)
      {
        res = curr;
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
