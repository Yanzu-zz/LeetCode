#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution713
{
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    if (k <= 1)
      return 0;

    int n = nums.size(), res = 0, sum = 1;
    queue<int> slide;

    for (int i = 0; i < n; i++)
    {
      slide.emplace(nums[i]);
      sum *= nums[i];

      // 必须严格小于 k 才能算一个合法的子数组
      while (sum >= k)
      {
        // 把最左边的元素移除
        sum /= slide.front();
        slide.pop();
      }
      if (sum <= 0)
        sum = 1;

      // 此时该组合算一个合法数组
      if (slide.size() > 0 && sum < k)
        res++;
    }

    // 添加完还可能有剩下的
    while (slide.size() > 0)
    {
      if (sum < k)
        res++;
      sum /= slide.front();
      slide.pop();
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
