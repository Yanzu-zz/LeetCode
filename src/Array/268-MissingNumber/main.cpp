#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution268
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    unordered_set<int> set;
    // 哈希表记录
    for (int i = 0; i < n; i++)
      set.insert(nums[i]);

    // 看看哪个数字没有出现过
    for (int i = 0; i <= n; i++)
      if (set.count(i) == 0)
        return i;

    return 0;
  }
};

int main()
{

  return 0;
}