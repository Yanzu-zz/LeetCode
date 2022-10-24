#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int partitionDisjoint(vector<int> &nums)
  {
    int n = nums.size();

    int index = 0; // 最终分割数组的索引
    int leftMax = nums[0], max = nums[0];

    for (int i = 0; i < n; i++)
    {
      int curr = nums[i];
      if (leftMax > curr)
      {
        index = i;
        leftMax = max;
      }
      else
      {
        max = curr > max ? curr : max;
      }
    }

    return index + 1;
  }
};

int main(void)
{

  return 0;
}
