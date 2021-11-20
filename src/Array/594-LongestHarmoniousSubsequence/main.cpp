#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int findLHS(vector<int> &nums)
  {
    int n = nums.size(), res = 0;
    unordered_map<int, int> mp;
    unordered_set<int> set;

    // 先加入数组的元素
    for (const auto &num : nums)
      mp[num]++;

    // 然后就是看看相邻的两个元素哪个多和少了
    for (const auto &num : nums)
    {
      if (set.count(num) != 0) // 剪枝
        continue;

      int result = mp[num + 1] == 0 ? 0 : mp[num] + mp[num + 1];
      res = max(res, result);
      set.insert(num);
    }

    return res;
  }
};

int main()
{

  return 0;
}