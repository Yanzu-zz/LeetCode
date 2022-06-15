#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution719
{
public:
  // 统计距离（数值之差的绝对值）小于等于 threshold 的个数
  int countLessEquals(vector<int> &nums, int threshold)
  {
    int n = nums.size(), res = 0;
    for (int left = 0, right = 0; right < n; right++)
    {
      // 当左右差值大于 threshold 时，左端点往右左，直到满足条件
      while (nums[right] - nums[left] > threshold)
        left++;

      // 每轮都会新增一些数对，记录下数量
      res += right - left;
    }

    return res;
  }

  int smallestDistancePair(vector<int> &nums, int k)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    // 确定左右最大差值
    int l = 0, r = nums[n - 1] - nums[0];
    while (l < r)
    {
      int mid = l + (r - l >> 1);
      // 尝试当前 mid 差值与 k 的关系
      int count = countLessEquals(nums, mid);
      if (count < k)
        l = mid + 1;
      else
        r = mid;
    }

    return l;
  }
};

int main()
{

  return 0;
}