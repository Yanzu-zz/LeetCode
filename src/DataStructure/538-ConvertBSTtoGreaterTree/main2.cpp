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

class Solution538
{
private:
  TreeNode *getSuccessor(TreeNode *node)
  {
    TreeNode *succ = node->right;

    while (succ->left != nullptr && succ->left != node)
      succ = succ->left;

    return succ;
  }

public:
  TreeNode *convertBST(TreeNode *root)
  {
    int sum = 0;
    TreeNode *node = root;

    //  利用 J. H. Morris 算法 来实现反序中序遍历 O(1)空间复杂度
    while (node != nullptr)
    {
      if (node->right == nullptr)
      {
        sum += node->val;
        node->val = sum;
        node = node->left;
      }
      else
      {
        TreeNode *succ = getSuccessor(node);
        if (succ->left == nullptr)
        {
          succ->left = node;
          node = node->right;
        }
        else
        {
          succ->left = nullptr;
          sum += node->val;
          node->val = sum;
          node = node->left;
        }
      }
    }
    
    return root;
  }
};

int main()
{

  return 0;
}