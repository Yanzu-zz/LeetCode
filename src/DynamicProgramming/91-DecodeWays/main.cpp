#include <iostream>
#include <vector>

using namespace std;

/**
 * dp 解法
 * dp[i] 表示字符串 s 前 i 个字符的解法方法数量
 * dp[i] = dp[i-1] if dp[i-1] != '0'
 * dp[i] += dp[i-2] if dp[i-2] != '0' && (dp[i-2] - '0')*10 + (dp[i-1] - '0') <=26
 * 
 * 注意， 这里dp 是从 1 开始的，s 是从0 开始的，故它们之间相差 1，即 dp[i] = s[i-1]
 */
class Solution91
{
public:
  int numDecodings(string s)
  {
    int n = s.size();

    // 初始化
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    // 开始 dp，注意，这里必须是循环到 n
    for (int i = 1; i <= n; i++)
    {
      if (s[i - 1] != '0')
        dp[i] = dp[i - 1];

      // 注意好对应的索引
      if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)
        dp[i] += dp[i - 2];
    }

    return dp[n];
  }
};

int main(void)
{
  string s1 = "12";
  string s2 = "226";
  string s3 = "12261";
  string s4 = "06";
  string s5 = "0";
  string s6 = "012312";

  cout << Solution91().numDecodings(s1) << endl;
  cout << Solution91().numDecodings(s2) << endl;
  cout << Solution91().numDecodings(s3) << endl;
  cout << Solution91().numDecodings(s4) << endl;
  cout << Solution91().numDecodings(s5) << endl;
  cout << Solution91().numDecodings(s6) << endl;

  return 0;
}
