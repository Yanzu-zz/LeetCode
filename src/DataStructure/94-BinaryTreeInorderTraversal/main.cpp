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

class Solution94
{
private:
  void inorder(TreeNode *curr, vector<int> &ret)
  {
    if (curr == nullptr)
      return;

    inorder(curr->left, ret);
    ret.push_back(curr->val);
    inorder(curr->right, ret);
  }

public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ret;
    inorder(root, ret);

    return ret;
  }
};

int main(void)
{

  return 0;
}
