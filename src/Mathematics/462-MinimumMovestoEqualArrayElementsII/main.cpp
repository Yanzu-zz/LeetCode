#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution462
{
public:
  int minMoves2(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int res = 0, median = nums[n >> 1];

    // 每个元素与中位数之差就是最小移动次数
    for (int i = 0; i < n; i++)
      res += abs(nums[i] - median);

    return res;
  }
};

int main(void)
{

  return 0;
}
