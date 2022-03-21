#include <iostream>
#include <vector>
#include <unordered_map>

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

class Solution653
{
private:
  unordered_map<int, int> mp;

public:
  bool findTarget(TreeNode *root, int k)
  {
    if (root == nullptr)
      return false;

    // 如果找到了另一个值加起来等于 k，则返回 true
    if (mp[k - root->val] != 0)
      return true;
    // 然后存下来当前值给别的节点判断
    mp[root->val]++;

    // 如果当前节点不是的话就继续在子节点上重复这个动作
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};

int main(void)
{

  return 0;
}
