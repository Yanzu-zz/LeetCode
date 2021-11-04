#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution494
{
private:
  int backtrack(vector<int> &nums, int target, int currIdx, int sum, unordered_map<string, int> &memo)
  {
    string key = to_string(currIdx) + "_" + to_string(sum);
    if (memo.count(key) != 0)
      return memo[key];

    // 当索引越界后就会来到这个边界条件判断
    if (currIdx == nums.size())
    {
      memo[key] = (sum == target ? 1 : 0);
      return memo[key];
    }

    // 当还没有越界的时候每个元素都有 + 和 - 两种情况，我们分别回溯一次就行
    int plus = backtrack(nums, target, currIdx + 1, sum + nums[currIdx], memo);
    int subt = backtrack(nums, target, currIdx + 1, sum - nums[currIdx], memo);

    memo[key] = plus + subt;
    return plus + subt;
  }

public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    unordered_map<string, int> memo;
    return backtrack(nums, target, 0, 0, memo);
  }
};

int main()
{

  return 0;
}