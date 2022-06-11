#include <iostream>
#include <vector>

using namespace std;

class Solution926
{
public:
  int minFlipsMonoIncr(string s)
  {
    int n = s.size();
    int dp0 = 0, dp1 = 0;

    for (int i = 0; i < n; i++)
    {
      // 先更新dp[i][1]，需要用到dp[i-1][0]
      dp1 = min(dp0, dp1) + ('1' - s[i]);
      // 0 前面只能是 0，不能为 1，s[i] - '0' == 1 就是找到了一个 1，需要翻转一次
      dp0 += s[i] - '0';
    }

    return min(dp0, dp1);
  }
};

int main()
{

  return 0;
}