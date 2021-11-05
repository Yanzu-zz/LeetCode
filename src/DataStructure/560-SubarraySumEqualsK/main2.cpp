#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution560
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();
    int res = 0, pre = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for (const auto &num : nums)
    {
      pre += x;
      if (mp.find(pre - k) != mp.end())
        res += mp[pre - k];

      mp[pre]++;
    }

    return res;
  }
};

int main()
{

  return 0;
}