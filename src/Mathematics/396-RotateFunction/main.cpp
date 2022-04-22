#include <iostream>
#include <vector>

using namespace std;

class Solution396
{
public:
  int maxRotateFunction(vector<int> &nums)
  {
    // sum 为 nums 的和，res 为题目要求的和算数式
    int n = nums.size(), sum = 0, pre = 0;
    if (n == 1)
      return 0;

    // 初始化 sum 和 求出 F(0)
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      pre += i * nums[i];
    }

    int cur = 0, res = pre;
    for (int i = 1; i < n; i++)
    {
      // 向右旋转一次，就相当于把当前结果加上整个数组的和，再减去数组大小乘以当前最后一位
      cur = pre + sum - n * nums[n - i];
      res = max(res, cur);
      pre = cur;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
