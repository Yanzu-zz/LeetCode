#include <iostream>
#include <vector>

using namespace std;

class Solution46
{
private:
  void swap(vector<int> &nums, int i, int j)
  {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }

  void backtrack(vector<vector<int>> &res, vector<int> nums, int first)
  {
    int len = nums.size();
    // 边界条件
    if (first == len)
    {
      res.emplace_back(nums);
      return;
    }

    for (int i = first; i < len; i++)
    {
      // 动态维护数组
      swap(nums, i, first);
      // 递归填充下一个数
      backtrack(res, nums, first + 1);
      // 回溯操作
      swap(nums, i, first);
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> res;
    backtrack(res, nums, 0);

    return res;
  }
};

int main()
{

  return 0;
}