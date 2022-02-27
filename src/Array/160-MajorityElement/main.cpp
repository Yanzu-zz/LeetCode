#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution160
{
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    int limit = n / 2;
    unordered_map<int, int> mp;

    for (int num : nums)
    {
      mp[num]++;
      if (mp[num] > limit)
        return num;
    }

    return nums[0];
  }
};

int main(void)
{

  return 0;
}
