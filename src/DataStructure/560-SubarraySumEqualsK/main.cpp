#include <iostream>
#include <vector>

using namespace std;

class Solution560
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = i; j >= 0; j--)
      {
        sum += nums[j];
        // 这里的和加起来为 k 时，不能 break 掉，因为可能会有复数，后面再次得到这个值
        if (sum == k)
          res++;
      }
    }

    return res;
  }
};

int main()
{

  return 0;
}