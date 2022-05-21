#include <iostream>
#include <vector>

using namespace std;

class Solution961
{
public:
  int repeatedNTimes(vector<int> &nums)
  {
    int n = nums.size();
    int start = nums[0], candidate = nums[0], len = n / 2 + 1;

    // 摩尔投票法
    for (int i = 1; i <= len; i++)
    {
      if (nums[i] == start)
        return start;
      if (nums[i] == candidate)
        return candidate;

      candidate = nums[i];
    }

    return candidate;
  }
};

int main(void)
{

  return 0;
}
