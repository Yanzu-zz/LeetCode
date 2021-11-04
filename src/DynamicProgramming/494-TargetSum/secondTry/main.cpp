#include <iostream>
#include <vector>

using namespace std;

class Solution494
{
private:
  int count = 0;
  void backtrack(vector<int> &nums, int target, int currIdx, int sum)
  {
    // 当索引越界后就会来到这个边界条件判断
    if (currIdx == nums.size())
    {
      if (sum == target)
        count++;
    }
    else
    {
      // 当还没有越界的时候每个元素都有 + 和 - 两种情况，我们分别回溯一次就行
      backtrack(nums, target, currIdx + 1, sum + nums[currIdx]);
      backtrack(nums, target, currIdx + 1, sum - nums[currIdx]);
    }
  }

public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    backtrack(nums, target, 0, 0);
    return count;
  }
};

int main()
{

  return 0;
}