#include <iostream>
#include <vector>

using namespace std;

/**
 * 在二分查找的每一步中，左边界为low，右边界为high，区间的中点为piot，
 * 最小值就在该区间内。我们将中轴元素 nums[pivot]与右边界元素 nums[high]进行比较，可能会有以下的三种情况
 * 第一种情况是 nums[piot]< nums[high]
 *  这说明 nums[pivo]是最小值右侧的元素，因此我们可以忽略二分查找区间的右半部分
 * 
 * 第二种情况是 nums[pivo] > nums[high]。
 *  这说明 mums[pivot]是最小值左侧的元素，因此我们可以忽略二分查找区间的左半部分。
 * 
 * 由于数组不包含重复元素，并且只要当前的区间长度不为1，piot就不会与high重合；
 * 而如果当前的区间长度为1，这说明我们已经可以结束二分查找了。因此不会存在 nums[piot] = nums[high]
 * 当二分查找结束时，我们就得到了最小值所在的位置。
 */
class Solution153
{
public:
  int findMin(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1 || nums[0] < nums[n - 1])
      return nums[0];

    // 开始二分
    int left = 0, mid, right = n - 1;
    while (left < right)
    {
      mid = left + (right - left) / 2;
      // 接下来就是笔记里写好的两种情况
      if (nums[mid] < nums[right])
        right = mid;
      else
        left = mid + 1;
    }

    return nums[mid];
  }
};

int main(void)
{
  vector<int> arr1 = {3, 4, 5, 1, 2};
  vector<int> arr2 = {4, 5, 6, 7, 0, 1, 2};
  vector<int> arr3 = {11, 13, 15, 17};

  cout << Solution153().findMin(arr1) << endl;
  cout << Solution153().findMin(arr2) << endl;
  cout << Solution153().findMin(arr3) << endl;

  return 0;
}
