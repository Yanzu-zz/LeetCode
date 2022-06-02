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

class Solution450
{
public:
  TreeNode *miniElement(TreeNode *curr)
  {
    if (curr->left == nullptr)
      return curr;

    return miniElement(curr->left);
  }

  TreeNode *removeMin(TreeNode *curr)
  {
    // Fine the smallest node
    if (curr->left == nullptr)
    {
      TreeNode *right = curr->right; // Although right tree node is null is not a matter
      delete curr;
      return right;
    }

    curr->left = removeMin(curr->left);
    return curr;
  }

  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == nullptr)
      return nullptr;

    // Use binary-search tree's characteristic
    // First, locate the speicific tree node
    if (root->val < key)
    {
      root->right = deleteNode(root->right, key);
    }
    else if (root->val > key)
    {
      root->left = deleteNode(root->left, key);
    }
    else // Then decide which type this node is
    {
      if (root->left == nullptr)
      {
        TreeNode *right = root->right;
        delete root;
        return right;
      }
      else if (root->right == nullptr)
      {
        TreeNode *left = root->left;
        delete root;
        return left;
      }
      else
      {
        // The hardest part
        // We should let the minimum element of root->right to replace root
        TreeNode *successor = new TreeNode(miniElement(root->right)->val);
        successor->right = removeMin(root->right);
        successor->left = root->left;
        return successor;
      }
    }

    return root;
  }
};

int main()
{

  return 0;
}