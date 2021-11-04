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

class Solution543
{
private:
  /**
   * 在每次获得一个节点的左子树和右子树的值的时候，都需要比较一下self.max和左子树高度+右子树高度的大小，把更大的保存下来
     然后如何求左子树和右子树的高度呢，那就是经典的递归求高度问题：max(depth(root.left), depth(root.right))+1
   */
  int preorder(TreeNode *node, int &res)
  {
    if (node == nullptr)
      return 0;

    int left = preorder(node->left, res);
    int right = preorder(node->right, res);
    res = max(res, left + right + 1); // res 则是记录的是当前最大直径

    return max(left, right) + 1; // 返回的是高度
  }

public:
  int diameterOfBinaryTree(TreeNode *root)
  {
    int res = 0;
    preorder(root, res);
    return res;
  }
};

int main()
{

  return 0;
}