#include <iostream>
#include <vector>

using namespace std;

// 暴力计算最优值（配合记忆化搜索）
class Solution198
{
private:
  // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益
  vector<int> memo;

  // 考虑抢劫 nums[index...nums.size()] 这个范围内的所有房子
  int tryRob(vector<int> &nums, int index)
  {
    if (index >= nums.size())
      return 0;

    if (memo[index] != -1)
      return memo[index];

    int res = 0; // 同时比较当前的收益和抢完这个和隔个房子的收益哪个更优
    for (int i = index; i < nums.size(); i++)
      res = max(res, nums[i] + tryRob(nums, i + 2)); // 考虑抢完当前的房子后，继续考虑隔一个位置的房子

    return memo[index] = res;
  }

public:
  int rob(vector<int> &nums)
  {
    memo = vector<int>(nums.size(), -1);
    return tryRob(nums, 0);
  }
};

int main()
{
  vector<int> arr1 = {1, 2, 3, 1};
  vector<int> arr2 = {2, 7, 9, 3, 1};

  cout << Solution198().rob(arr1) << endl;
  cout << Solution198().rob(arr2) << endl;

  return 0;
}