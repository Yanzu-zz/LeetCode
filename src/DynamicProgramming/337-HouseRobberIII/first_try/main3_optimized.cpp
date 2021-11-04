#include <iostream>
#include <vector>

using namespace std;

/**
 * 解法三、终极解法
    上面两种解法用到了孙子节点，计算爷爷节点能偷的钱还要同时去计算孙子节点投的钱，虽然有了记忆化，但是还是有性能损耗。
    
    我们换一种办法来定义此问题：
    每个节点可选择偷或者不偷两种状态，根据题目意思，相连节点不能一起偷
      当前节点选择偷时，那么两个孩子节点就不能选择偷了
      当前节点选择不偷时，两个孩子节点只需要拿最多的钱出来就行(两个孩子节点偷不偷没关系)
      
    我们使用一个大小为 2 的数组来表示 int[] res = new int[2] 0 代表不偷，1 代表偷
    
    任何一个节点能偷到的最大钱的状态可以定义为
      - 当前节点选择不偷：当前节点能偷到的最大钱数 = 左孩子能偷到的钱 + 右孩子能偷到的钱
      - 当前节点选择偷：当前节点能偷到的最大钱数 = 左孩子选择自己不偷时能得到的钱 + 右孩子选择不偷时能得到的钱 + 当前节点的钱数
    
    表示为公式如下
      root[0] = Math.max(rob(root.left)[0].rob(root.left)[1]) + Math.max(rob(root.right)[0], rob(root.right)[1])
      root[1] = rob(root.left)[0] + rob(root.right)[0] + root.val;
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution337
{
private:
  int *robInternal(TreeNode *root)
  {
    int *t = new int[2];
    if (root == NULL)
      return t;

    // 后序遍历树接着用我们上边的定义计算最大收益
    int *left = robInternal(root->left);
    int *right = robInternal(root->right);

    t[0] = max(left[0], left[1]) + max(right[0], right[1]); // 选择不偷
    t[1] = left[0] + right[0] + root->val;                  // 选择偷

    return t;
  }

public:
  int rob(TreeNode *root)
  {
    int *result = robInternal(root);
    return max(result[0], result[1]);
  }
};

int main(void)
{

  return 0;
}
