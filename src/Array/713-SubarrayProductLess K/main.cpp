#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    int n = nums.size(), ret = 0;
    int prod = 1, i = 0;

    for (int j = 0; j < n; j++)
    {
      prod *= nums[j];
      // 如果超过了 k 就要将最左侧的元素出数组并且 prod 除于它
      while (i <= j && prod >= k)
      {
        prod /= nums[i];
        i++;
      }

      // 窗口2对比窗口1多出来的数组都是由于窗口右滑一次所带来的，即多出来的那几个必然是包含新窗口的边界r的
      ret += j - i + 1;
    }

    return ret;
  }
};

int main(void)
{

  return 0;
}
