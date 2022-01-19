#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution219
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    int n = nums.size();
    unordered_map<int, int> mp; // 存储的是 <元素, 元素索引>

    for (int i = 0; i < n; i++)
    {
      // 遇到一个新元素则对比一次
      if (mp.count(nums[i]) != 0)
      {
        int numIdx = mp[nums[i]];
        if (i - numIdx <= k)
          return true;
      }

      // 对比完一次是否重复元素则更新当前元素最新位置
      mp[nums[i]] = i;
    }

    return false;
  }
};

int main(void)
{

  return 0;
}
