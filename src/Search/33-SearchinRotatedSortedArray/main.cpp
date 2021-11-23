#include <iostream>
#include <vector>

using namespace std;

class Solution33
{
public:
  int search(vector<int> &nums, int target)
  {
    int n = nums.size();
    if (!n)
      return -1;
    if (n == 1)
      return nums[0] == target ? 0 : -1;

    // 开始二分
    int l = 0, r = n - 1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      if (nums[mid] == target)
        return mid;
      // 4 5 6 7 0 1 2 这种情况
      if (nums[0] <= nums[mid])
      {
        // 此时要找的 target 比当前中间数要小，故我们把右指针挪到中间来
        if (nums[0] <= target && target < nums[mid])
          r = mid - 1;
        else // 这里就是要找的 target 比中间数要大，我们把左指针挪到右边来
          l = mid + 1;
      }
      else // 6 7 0 1 2 3 4 5 这种情况
      {
        // 这边逻辑和上面一直，自己思考一下就行
        if (nums[mid] < target && target <= nums[n - 1])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }

    return -1;
  }
};

int main()
{

  return 0;
}