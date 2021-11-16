#include <iostream>
#include <vector>

using namespace std;

class Solution05
{
public:
  string longestPalindrome(string s)
  {
    int n = s.size();
    int maxSubLen = INT_MIN;
    string maxSub = ""; // 返回数组
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // 开始 dp
    for (int j = 0; j < n; j++)
    {
      for (int i = 0; i <= j; i++)
      {
        // 判断是否回文子串核心逻辑
        if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
          dp[i][j] = true;

        if (dp[i][j] && j - i > maxSubLen)
        {
          maxSub = s.substr(i, j - i + 1);
          maxSubLen = j - i;
        }
      }
    }

    return maxSub;
  }
};

int main()
{

  return 0;
}