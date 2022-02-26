#include <iostream>
#include <vector>

using namespace std;

class Solution2016
{
public:
  int maximumDifference(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> arr(n, 0);
    arr[n - 1] = nums[n - 1];

    // 寻找当前位置的最大值
    for (int i = n - 2; i >= 0; i--)
      arr[i] = nums[i] > arr[i + 1] ? nums[i] : arr[i + 1];

    // 然后就开始计算最大差值
    int res = -1;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] < arr[i])
        res = max(res, arr[i] - nums[i]);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
