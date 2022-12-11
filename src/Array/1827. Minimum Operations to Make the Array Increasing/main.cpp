#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    int n = nums.size();

    int currVal = nums[0] + 1, res = 0;

    for (int i = 1; i < n; i++)
    {
      if (nums[i] >= currVal)
        currVal = nums[i] + 1;
      else
      {
        res += currVal - nums[i];
        currVal++;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
