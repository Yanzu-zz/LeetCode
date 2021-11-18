#include <iostream>
#include <vector>
#include <cmath>

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

class Solution563
{
private:
  // 注意，这里返回的值是当前 root 节点下所有节点的和
  int postOrder(TreeNode *root, int &res)
  {
    if (root == nullptr)
      return 0;

    // 先遍历完左右子树先
    int left = postOrder(root->left, res);
    int right = postOrder(root->right, res);

    // 然后计算差值
    res += abs(left - right);

    return root->val + left + right; // 返回这个节点的值和所有子节点的和以供父节点再使用
  }

public:
  int findTilt(TreeNode *root)
  {
    int res = 0;
    postOrder(root, res);

    return res;
  }
};

int main()
{

  return 0;
}