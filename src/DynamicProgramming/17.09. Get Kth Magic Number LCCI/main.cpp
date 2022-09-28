#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int getKthMagicNumber(int k)
  {
    vector<int> dp(k + 1);
    dp[1] = 1;
    int p3 = 1, p5 = 1, p7 = 1;

    for (int i = 2; i <= k; i++)
    {
      int num3 = dp[p3] + (dp[p3] << 1);
      int num5 = dp[p5] + (dp[p5] << 2);
      int num7 = (dp[p7] << 3) - dp[p7];

      dp[i] = min(min(num3, num5), num7);
      if (dp[i] == num3)
        p3++;
      if (dp[i] == num5)
        p5++;
      if (dp[i] == num7)
        p7++;
    }

    return dp[k];
  }
};

int main(void)
{
  Solution().getKthMagicNumber(9);

  return 0;
}
