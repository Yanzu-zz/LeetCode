#include <iostream>
#include <vector>

using namespace std;

/**
 * 双指针解法，详情看笔记
 */
class Solution209
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int n = nums.size();
    int sum = nums[0], ret = INT_MAX;
    int left = 0, right = 1;

    while (left < n)
    {
      if (sum < target)
      {
        if (right < n)
          sum += nums[right++]; // 右指针右移
        else
          break;
      }
      else // 当几个连续的元素的和超过 target 时，更新最短连续数组长度，并 left 左移，别忘了 sum 要减去左移元素
      {
        ret = min(ret, right - left);
        if (ret == 1)
          break;
        sum -= nums[left++];
      }
    }

    return ret == INT_MAX ? 0 : ret;
  }
};

int main(void)
{
  vector<int> arr1 = {2, 3, 1, 2, 4, 3};
  int target1 = 7;
  vector<int> arr2 = {1, 1, 1, 1, 1, 1, 1};
  int target2 = 11;
  vector<int> arr3 = {1, 4, 4};
  int target3 = 4;

  cout << Solution209().minSubArrayLen(target1, arr1) << endl;
  cout << Solution209().minSubArrayLen(target2, arr2) << endl;
  cout << Solution209().minSubArrayLen(target3, arr3) << endl;

  return 0;
}
