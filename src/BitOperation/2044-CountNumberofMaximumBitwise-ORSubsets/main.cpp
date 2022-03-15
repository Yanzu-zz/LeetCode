#include <iostream>
#include <vector>

using namespace std;

class Solution2044
{
public:
  int countMaxOrSubsets(vector<int> &nums)
  {
    int n = nums.size(), maxOrVal = 0, res = 0; // res 初始化为 0 是因为当下面循环 i 为 11...11 即 2^n - 1 时一定会再遍历一次整个数组

    // 一个数组最大的 or 值一定是把全部值 or 一遍，故我们这样就得到最大值了
    for (int num : nums)
      maxOrVal |= num;

    // 接下来就是看看子数组还有没有可能 or 到这个最大值
    // 遍历范围为 (2^n) - 2，每个数字的某个位 i 为 1 则表明第 i 位代表了集合下标为 i 的元素出现
    int len = 1 << n; // 1 << n == 2^n - 1
    for (int i = 1; i < len; i++)
    {
      int cur = 0;
      for (int j = 0; j < n; j++)
        if (i & (1 << j)) // 如果当前位置是状态 1 的话就 or 起来
          cur |= nums[j];

      // 只可能等于最大 or 值不可能超过它
      if (cur == maxOrVal)
        res++;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
