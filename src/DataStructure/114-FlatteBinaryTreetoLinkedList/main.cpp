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

class Solution114
{
public:
  void flatten(TreeNode *root)
  {
    while (root != nullptr)
    {
      if (root->left == nullptr) // 左子树为空的话就没有必要操作了，直接挪移到当前节点的右子树
      {
        root = root->right;
      }
      else
      {
        // 有左子树的话就找到它的左子树的最下最右边节点
        TreeNode *leftSubTreeNode = root->left;
        while (leftSubTreeNode->right != nullptr)
          leftSubTreeNode = leftSubTreeNode->right;

        // 然后根据笔记中的过程，将该右下节点指向当前节点的右子树
        leftSubTreeNode->right = root->right;
        // 然后将当前节点的左子树挪到右子树上
        root->right = root->left;
        root->left = nullptr;

        // 当前轮次执行完毕，考虑下一个节点
        root = root->right;
      }
    }
  }
};

int main(void)
{

  return 0;
}
