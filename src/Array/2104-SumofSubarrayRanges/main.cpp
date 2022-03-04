#include <iostream>
#include <vector>

using namespace std;

class Solution2104
{
public:
  long long subArrayRanges(vector<int> &nums)
  {
    int n = nums.size();
    long long res = 0;

    for (int i = 0; i < n; i++)
    {
      int minVal = nums[i], maxVal = nums[i];
      for (int j = i + 1; j < n; j++)
      {
        // 每回合都更新下区间最大最小值然后相减
        minVal = min(minVal, nums[j]);
        maxVal = max(maxVal, nums[j]);
        res += maxVal - minVal;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
