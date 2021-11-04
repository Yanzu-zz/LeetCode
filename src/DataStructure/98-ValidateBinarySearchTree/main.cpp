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

class Solution98
{
private:
  void preOrder(TreeNode *curr, vector<int> &arr)
  {
    if (curr == nullptr)
      return;

    preOrder(curr->left, arr);
    arr.push_back(curr->val);
    preOrder(curr->right, arr);
  }

public:
  bool isValidBST(TreeNode *root)
  {
    vector<int> ret;
    preOrder(root, ret);

    int n = ret.size();
    for (int i = 0; i < n - 1; i++)
      if (ret[i] >= ret[i + 1]) // 严格升序，故等于下个元素也不行
        return false;

    return true;
  }
};

int main(void)
{

  return 0;
}
