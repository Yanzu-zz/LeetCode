#include <iostream>
#include <vector>

using namespace std;

/**
 * dp 解法 - 空间优化方案
 * 我们注意到我们之前写的 dp 只需要保存 3 个数值，故我们这里用 3 个滚动变量存储它们即可
 * 
 * 注意， 这里dp 是从 1 开始的，s 是从0 开始的，故它们之间相差 1，即 dp[i] = s[i-1]
 */
class Solution91
{
public:
  int numDecodings(string s)
  {
    int n = s.size();
    if (s[0] == '0')
      return 0;

    // 初始化，a=dp[i-2], b=dp[i-1], c=dp[i]
    int a = 0, b = 1, c = 1;

    // 开始 dp
    for (int i = 1; i <= n; i++)
    {
      c = 0;
      if (s[i - 1] != '0')
        c += b;

      // 注意好对应的索引
      if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)
        c += a;

      a = b;
      b = c;
    }

    return c;
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
  string s7 = "10";

  cout << Solution91().numDecodings(s1) << endl;
  cout << Solution91().numDecodings(s2) << endl;
  cout << Solution91().numDecodings(s3) << endl;
  cout << Solution91().numDecodings(s4) << endl;
  cout << Solution91().numDecodings(s5) << endl;
  cout << Solution91().numDecodings(s6) << endl;
  cout << Solution91().numDecodings(s7) << endl;

  return 0;
}
