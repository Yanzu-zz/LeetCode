#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution215
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    // 暴力做法
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};

int main(void)
{

  return 0;
}
