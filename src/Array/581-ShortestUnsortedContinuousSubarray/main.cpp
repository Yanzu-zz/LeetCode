#include <iostream>
#include <vector>

using namespace std;

class Solution581
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    int n = nums.size();
    int begin = 0, end = -1;
    int maxVal = nums[0], minVal = nums[n - 1];

    for (int i = 0; i < n; i++)
    {
      // 从左往右判断，比当前记录的最大元素大于等于就更新最大元素；否则就更新 无序子数组的右边界
      if (nums[i] > maxVal)
        maxVal = nums[i];
      else
        end = i;

      // 从右往左判断，比当前记录的最小元素小于等于就更新最小元素；否则就更新 无序子数组的左边界
      // 我们可以不用两次循环，我们用索引偏移的方式计算就行
      int rightToLeftIdx = n - 1 - i;
      if (nums[rightToLeftIdx] < minVal)
        minVal = nums[rightToLeftIdx];
      else
        begin = rightToLeftIdx;
    }

    return end - begin + 1; // 因为求得是长度，这里我们数组天生就要 + 1
  }
};

int main()
{

  return 0;
}