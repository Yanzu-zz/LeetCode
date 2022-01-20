#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution219
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    int n = nums.size();
    if (k == 0 || n == 1)
      return false;

    unordered_set<int> set; // k 个长度大小的滑动窗口

    for (int i = 0; i < n; i++)
    {
      int num = nums[i];
      // 如果在滑动窗口内存在相同元素则表明有确定规则的重复元素
      if (set.count(num))
        return true;

      // 然后加入当前元素
      set.insert(num);
      // 数量超过 k 的话就去掉最前面的元素
      if (set.size() > k)
        set.erase(nums[i - k]);
    }

    return false;
  }
};

int main(void)
{

  return 0;
}
