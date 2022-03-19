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

class Solution606
{
private:
  string _tree2str(TreeNode *curr)
  {
    if (curr == nullptr)
      return "";

    // 若当前节点为叶子节点则直接返回自身
    if (curr->left == nullptr && curr->right == nullptr)
      return to_string(curr->val);

    // 若右节点为空则直接返回 自身和左节点
    if (curr->right == nullptr)
      return to_string(curr->val) + "(" + _tree2str(curr->left) + ")";

    // 否则正常左右递归（这样左节点为空也会有空括号
    return to_string(curr->val) + "(" + _tree2str(curr->left) + ")" + "(" + _tree2str(curr->right) + ")";
  }

public:
  string tree2str(TreeNode *root)
  {
    string res = _tree2str(root);

    return res;
  }
};

int main(void)
{

  return 0;
}
