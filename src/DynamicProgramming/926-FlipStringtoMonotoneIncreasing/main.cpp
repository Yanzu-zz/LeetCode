#include <iostream>
#include <vector>

using namespace std;

class Solution926
{
public:
  int minFlipsMonoIncr(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
    {
      // 把第 i 个字符变成 0
      dp[i + 1][0] = dp[i][0] + (s[i] - '0');
      // 变成 1
      dp[i + 1][1] = min(dp[i][0], dp[i][1]) + (s[i] == '0');
    }

    return min(dp[n][0], dp[n][1]);
  }
};

int main()
{

  return 0;
}