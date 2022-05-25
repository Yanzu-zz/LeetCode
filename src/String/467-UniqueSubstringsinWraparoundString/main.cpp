#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution467
{
public:
  int findSubstringInWraproundString(string p)
  {
    int n = p.size(), cnt = 1;
    vector<int> dp(26, 0); // dp 数组

    int prev = p[0] - 'a';
    dp[prev] = 1;
    for (int i = 1; i < n; i++)
    {
      /* 由于串是环状的所以两边都需要%26 */
      cnt = ((prev + 1) % 26 == (p[i] - 'a') % 26) ? cnt + 1 : 1;

      /* p[i]-'a'是得到对应dp数组下标 */
      prev = p[i] - 'a';
      // 此时对比（之前有的话）的结果与当前 cnt 的大小
      dp[prev] = max(dp[prev], cnt);
    }

    /* 将所有增量累加，就是非空子串的数量 */
    // return accumulate(dp.begin(), dp.end(), 0);
    int res = 0;
    for (int &v : dp)
      res += v;
    return res;
  }
};

int main(void)
{

  return 0;
}
