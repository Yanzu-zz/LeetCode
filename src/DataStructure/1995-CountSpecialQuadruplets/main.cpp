#include <iostream>
#include <vector>

using namespace std;

class Solution1995
{
public:
  int countQuadruplets(vector<int> &nums)
  {
    int res = 0;
    int n = nums.size();

    // 暴力就完事了
    for (int a = 0; a < n; a++)
      for (int b = a + 1; b < n; b++)
        for (int c = b + 1; c < n; c++)
          for (int d = c + 1; d < n; d++)
            if (nums[a] + nums[b] + nums[c] == nums[d])
              res++;

    return res;
  }
};

int main(void)
{

  return 0;
}
