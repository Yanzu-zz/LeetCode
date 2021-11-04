#include <iostream>
#include <vector>

using namespace std;

/**
 * 解题思路：f(n) = f(n-1) + f(n-2)
 */
class Solution70
{
public:
  int climbStairs(int n)
  {
    if (n == 0 || n == 1)
      return 1;

    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; i++)
      dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
  }
};

int main(void)
{
  int n1 = 3;
  int n2 = 5;

  cout << Solution70().climbStairs(n1) << endl;
  cout << Solution70().climbStairs(n2) << endl;

  return 0;
}
