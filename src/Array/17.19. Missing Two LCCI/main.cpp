#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> missingTwo(vector<int> &nums)
  {
    int totalLength = nums.size() + 2;
    int totalSum = ((totalLength + 1) * totalLength) >> 1;
    for (int num : nums)
      totalSum -= num;
    int missingHalf = totalSum >> 1;
    int missingHalfSum = ((missingHalf + 1) * missingHalf) >> 1;
    for (int num : nums)
      if (num <= missingHalf)
        missingHalfSum -= num;

    vector<int> res = {missingHalfSum, totalSum - missingHalfSum};
    return res;
  }
};

int main(void)
{
  vector<int> a0 = {3};
  Solution().missingTwo(a0);

  vector<int> a1 = {1, 8, 6, 3, 10, 9, 2, 5};
  Solution().missingTwo(a1);

  return 0;
}
