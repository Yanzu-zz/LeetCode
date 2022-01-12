#include <iostream>
#include <vector>

using namespace std;

class Solution334
{
public:
  bool increasingTriplet(vector<int> &nums)
  {
    int n = nums.size();
    if (n < 3)
      return false;

    int small = INT_MAX - 1, mid = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      // 没找到三个的话就继续赋值查找
      // 即使我们更新了 small ，这个 small 在 mid 后面，没有严格遵守递增顺序，但它隐含着的真相是
      // 有一个比 small 大比 mid 小的前·最小值出现在 mid 之前
      if (nums[i] <= small)
        small = nums[i];
      else if (nums[i] <= mid)
        mid = nums[i];
      // 若已知有两个长度的上升子序列，且找到了比 mid 大的元素，则表明存在递增的三元子序列
      else
        return true;
    }

    return false;
  }
};

int main(void)
{

  return 0;
}
