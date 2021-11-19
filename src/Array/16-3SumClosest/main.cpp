#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution16
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    int n = nums.size();
    int tmp = INT_MAX, res = 0;
    // 先排序
    sort(nums.begin(), nums.end());

    for (int first = 0; first < n - 2; first++)
    {
      // 下个数字不能与上一个相同，不然后面会重复，那此轮就没意义了
      if (first > 0 && nums[first] == nums[first - 1])
        continue;

      // 第二个指针位置
      for (int second = first + 1; second < n - 1; second++)
      {
        // 同理，不能与上轮循环数值重复
        if (second > first + 1 && nums[second] == nums[second - 1])
          continue;

        // 边界条件
        for (int third = second + 1; third < n; third++)
        {
          int ThreeSumVal = nums[first] + nums[second] + nums[third];
          if (ThreeSumVal == target)
            return ThreeSumVal;

          int distance = (int)abs(ThreeSumVal - target); // 当前 3 数之和与目标 target 的距离差别
          if (distance < tmp)
          {
            tmp = distance;
            res = ThreeSumVal;
          }
        }
      }
    }

    return res;
  }
};

int main()
{
  vector<int> arr1 = {0, 2, 1, -3};
  cout << Solution16().threeSumClosest(arr1, 1) << endl;

  return 0;
}