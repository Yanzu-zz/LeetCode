#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution215
{
private:
  // 划分减治
  int partition(vector<int> &nums, int left, int right)
  {
    // 基准值
    int base = nums[left];
    int j = left; // 小于基准值的元素的边界

    // 开始 partition
    // 注意，left 是基准数，不需要处理，故 i 初始化为 left+1
    // 然后 right 位置也是需要处理的，故区间为 nums[left+1...right]
    for (int i = left + 1; i <= right; i++)
      if (nums[i] < base)
        swap(nums, i, ++j);

    // 交换基准值到它该在的位置
    swap(nums, left, j);
    return j;
  }

  // 交换数组元素位置
  void swap(vector<int> &nums, int i, int j)
  {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }

public:
  int findKthLargest(vector<int> &nums, int k)
  {
    int n = nums.size();

    int kIdx = 0, targetIdx = n - k;
    int left = 0, right = n - 1;
    while (left <= right)
    {
      // 做一次划分
      // 因为划分取的基准元素 base 是随机的（你也不可能直接取一个乱序数组的第 k 大元素，都能直接取了还划分干嘛）
      kIdx = partition(nums, left, right);
      // 如果当前轮次的划分找到了对应的索引点位，则返回
      if (kIdx == targetIdx)
        return nums[kIdx];
      else if (kIdx < targetIdx)
        left = kIdx + 1;
      else
        right = kIdx - 1;
    }

    return nums[kIdx];
  }
};

int main(void)
{

  return 0;
}
