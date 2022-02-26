#include <iostream>
#include <vector>

using namespace std;

class Solution2016
{
public:
  int maximumDifference(vector<int> &nums)
  {
    int n = nums.size();
    int res = -1, vMax = nums[n - 1];

    // 从右向左遍历
    for (int i = n - 2; i >= 0; i--)
    {
      // 如果当前位置的值比 vMax 大，则直接覆盖
      if (nums[i] > vMax)
        vMax = nums[i];
      else if (nums[i] < vMax)
        res = max(res, vMax - nums[i]);
      // 注意，等于不用计算
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
