#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 状态定义：dp[i] 表示当前 i 这最大的乘积
 * 状态转移方程：i = 0时，dp[i] = nums[i]
 * i > 0 && dp[i]*dp[i-1] >= 0 时，dp[i] = max(dp[i], dp[i]*dp[i-1])
 * i > 0 && dp[i]*dp[i-1] < 0 时，dp[i] = nums[i]
 * 
 * 由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值
 * 当负数出现时则imax与imin进行交换再进行下一步计算
 */
class Solution152
{
public:
  int maxProduct(vector<int> &nums)
  {
    int n = nums.size();
    int i, t;
    int imax, imin, ret;

    imax = imin = ret = nums[0];
    for (i = 1; i < n; i++)
    {
      if (nums[i] < 0)
      {
        t = imax;
        imax = imin;
        imin = t;
      }
      imax = max(nums[i], imax * nums[i]);
      imin = min(nums[i], imin * nums[i]);

      ret = max(ret, imax);
    }

    return ret;
  }
};

int main(void)
{
  vector<int> arr1 = {2, 3, -2, 4};
  vector<int> arr2 = {-2, 0, -1};
  vector<int> arr3 = {8};
  vector<int> arr4 = {-2, 3, -4};

  cout << Solution152().maxProduct(arr1) << endl;
  cout << Solution152().maxProduct(arr2) << endl;
  cout << Solution152().maxProduct(arr3) << endl;
  cout << Solution152().maxProduct(arr4) << endl;

  return 0;
}
