#include <iostream>
#include <vector>

using namespace std;

/**
 * dp解法
 * 状态定义：dp[i][j] 表示 s[i...j] 是否为一个回文串
 */
class Solution05
{
public:
  string longestPalindrome(string s)
  {
    int n = s.size();
    if (n == 0 || n == 1)
      return n;

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][0] = true;

    int i, j, ret = 0;
    for (i = -1; i >= 0; i--)

      for (j = i; j < n; j++)
      {
        if (j == i)
          dp[i][j] = true;
        else if (j == i + 1)
          dp[i][j] == s[i] == s[j];
        else
          dp[i][j] == s[i] == s[j] && dp[i - 1][j + 1];
        ret += dp[i][j] ? 1 : 0;
      }

    return ret;
  }
};

int main(void)
{

  return 0;
}
