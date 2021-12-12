#include <iostream>
#include <vector>

using namespace std;

class Solution62
{
public:
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> dp(m, vector(n, 1));

    // 开始 dp
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];

    return dp[m - 1][n - 1];
  }
};

int main(void)
{

  return 0;
}
