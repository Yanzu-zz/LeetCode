#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int arraySign(vector<int> &nums)
  {
    int n = nums.size();
    int negNum = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
        return 0;
      else if (nums[i] < 0)
        negNum++;
    }

    return negNum % 2 == 1 ? -1 : 1;
  }
};

int main(void)
{

  return 0;
}
