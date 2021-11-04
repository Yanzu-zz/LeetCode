#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 状态定义：LIS(i) 表示以第 i 个数字为结尾的最长上升子序列的长度
 * LIS(i) 表示 [o...i] 的范围内，选择数字 nums[i] 可以获得的最长上升子序列的长度
 * 注意，这里不像之前做的的题，是考虑一个范围的长度，而是一定要计算出这个范围内的长度
 * 
 * 基于这样的状态定义，我们就能推导出对应的状态转移方程
 *  LIS(i) = max(1 + LIS(j) if nums[i] > nums[j])
 */
class Solution300
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    if (nums.size() == 0)
      return 0;

    //  查找最长上升子序列的最长长度
    int res = 1;
    // memo[i] 表示的以 nums[i] 为结尾的最长上升子序列的长度
    // 注意，这里的初值其实已经定义好了（每个序列初始长度都为1）
    vector<int> memo(nums.size(), 1);

    // 我们是以第一个元素开始（小数据量），慢慢处理后面的元素上升子序列长度（变成处理大数据量）
    int j;
    for (int i = 1; i < nums.size(); i++)
    {
      for (j = 0; j < i; j++)
        if (nums[j] < nums[i])
          // 找到前面元素比我这个元素小的话
          // 就更新长度更大的数据（具体看笔记）
          memo[i] = max(memo[i], 1 + memo[j]);
      res = max(res, memo[i]);
    }

    // for (int item : memo)
    //   res = max(res, item);

    return res;
  }
};

int main(void)
{
  vector<int> arr1 = {10, 9, 2, 5, 3, 7, 101, 18};

  cout << Solution300().lengthOfLIS(arr1) << endl;

  return 0;
}
