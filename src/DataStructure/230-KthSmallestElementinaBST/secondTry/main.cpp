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

class Solution230
{
private:
  int count, K, res;
  void inorder(TreeNode *curr)
  {
    if (curr == nullptr)
      return;

    inorder(curr->left);
    if (++count == K)
    {
      res = curr->val;
      return;
    }
    inorder(curr->right);
  }

public:
  int kthSmallest(TreeNode *root, int k)
  {
    K = k;
    inorder(root);
    return res;
  }
};

int main(void)
{

  return 0;
}
