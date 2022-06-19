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

class Solution508
{
private:
  int maxCnt = 0;
  unordered_map<int, int> mp; // 记录子节点值出现的次数

  int dfs(TreeNode *curr)
  {
    if (curr == nullptr)
      return 0;

    int left = dfs(curr->left);
    int right = dfs(curr->right);

    // 左右子节点加上当前节点的值
    int tmp = left + right + curr->val;
    mp[tmp]++;
    maxCnt = max(maxCnt, mp[tmp]);

    return tmp;
  }

public:
  vector<int> findFrequentTreeSum(TreeNode *root)
  {
    dfs(root);

    // 记录完出现的次数后再遍历添加
    vector<int> res;
    for (auto it : mp)
    {
      if (it.second == maxCnt)
        res.emplace_back(it.first);
    }

    return res;
  }
};

int main()
{

  return 0;
}