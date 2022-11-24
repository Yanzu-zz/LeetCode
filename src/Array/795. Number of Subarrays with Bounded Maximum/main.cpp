#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
  {
    int n = nums.size(), res = 0;
    int idx1 = -1, idx2 = -1;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] > right)
        idx2 = i;
      if (nums[i] >= left)
        idx1 = i;
      res += idx1 - idx2;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
