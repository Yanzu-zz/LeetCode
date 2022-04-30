#include <iostream>
#include <vector>

using namespace std;

class Solution908
{
public:
  int smallestRangeI(vector<int> &nums, int k)
  {
    int n = nums.size();
    int m = INT_MAX, M = INT_MIN;

    // Search for the maxiumn and miniumn elements
    for (int num : nums)
    {
      m = min(m, num);
      M = max(M, num);
    }

    // k is a nonegative integer
    m += k;
    M -= k;

    return m >= M ? 0 : M - m;
  }
};

int main(void)
{

  return 0;
}
