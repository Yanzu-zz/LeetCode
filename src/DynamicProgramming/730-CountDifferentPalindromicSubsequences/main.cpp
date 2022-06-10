#include <iostream>
#include <vector>

using namespace std;

class Solution730
{
public:
  int countPalindromicSubsequences(string s)
  {
    int n = s.size(), MOD = 1000000007;
    // dp 数组，
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // 长度为一的字符回文子数为 1
    for (int i = 0; i < n; i++)
      dp[i][i] = 1;

    // 所以直接从长度为 2 的子串开始算
    for (int len = 2; len <= n; len++)
    {
      // i+len 为当前字符串边界
      for (int i = 0; i + len <= n; i++)
      {
        int j = i + len - 1; // 定位到右边后一个字符位置

        // 开始 dp
        // 情况（1）
        if (s[i] == s[j])
        {
          // left和right 控制边界&寻找当前子串中有多少个字符与 新来的左右字符 相等
          int left = i + 1;
          int right = j - 1;
          // 找到第一个和 s[i] 相同的字符（左边）
          while (left <= right && s[left] != s[i])
            left++;
          // 找到第一个和 s[j] 相同的字符（右边）
          while (left <= right && s[right] != s[j])
            right--;

          // 因为 s[i]==s[j]，所以有这两个情报就能判断有多少个重复字符了
          if (left > right)
            // 情况①，没有重复字符
            dp[i][j] = (dp[i + 1][j - 1] << 1) + 2;
          else if (left == right)
            // 情况②，有一个重复字符
            dp[i][j] = (dp[i + 1][j - 1] << 1) + 1;
          else
            // 情况③，有两个及以上重复字符
            dp[i][j] = (dp[i + 1][j - 1] << 1) - dp[left + 1][right - 1];
        }
        // 情况（2）
        else
        {
          dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
        }

        //处理超范围结果
        dp[i][j] = (dp[i][j] >= 0) ? dp[i][j] % MOD : dp[i][j] + MOD;
      }
    }

    return dp[0][n - 1];
  }
};

int main()
{

  return 0;
}