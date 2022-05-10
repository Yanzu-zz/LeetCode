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

class Solution108
{
private:
  TreeNode *buildTree(vector<int> &nums, int l, int r)
  {
    if (l > r)
      return nullptr;

    int mid = l + (r - l >> 1);
    TreeNode *curr = new TreeNode(nums[mid]);
    curr->left = buildTree(nums, l, mid - 1);
    curr->right = buildTree(nums, mid + 1, r);

    return curr;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    int n = nums.size();
    return buildTree(nums, 0, n - 1);
  }
};

int main(void)
{

  return 0;
}
