#include <iostream>
#include <vector>

using namespace std;

class Solution78_2
{
private:
  void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &tmp, int currIdx)
  {
    // 边界条件
    if (currIdx == nums.size())
    {
      res.emplace_back(tmp);
      return;
    }

    // 加入新的元素进去
    tmp.emplace_back(nums[currIdx]);
    dfs(nums, res, tmp, currIdx + 1);
    // 把上面加入的元素出列
    tmp.pop_back();
    // 然后以下一个元素的位置重新进行 dfs
    dfs(nums, res, tmp, currIdx + 1);
  }

public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<int> tmp;
    vector<vector<int>> res;
    dfs(nums, res, tmp, 0);
    return res;
  }
};

int main(void)
{

  return 0;
}
