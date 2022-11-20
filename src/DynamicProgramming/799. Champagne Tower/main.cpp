#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  double champagneTower(int poured, int query_row, int query_glass)
  {
    int len = query_row + 2;
    vector<vector<double>> dp(len, vector<double>(len));
    dp[1][1] = poured;

    for (int i = 2; i < len; i++)
      for (int j = 1; j <= i; j++)
        dp[i][j] = max(dp[i - 1][j - 1] - 1, 0.0) / 2 + max(dp[i - 1][j] - 1, 0.0) / 2;

    return min(dp[query_row + 1][query_glass + 1], 1.0);
  }
};

int main(void)
{

  return 0;
}
