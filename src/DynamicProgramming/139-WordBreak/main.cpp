#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution139
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    int n = s.size();

    vector<int> dp(n + 1, false);
    dp[0] = true;
    int i, j;
    for (i = 1; i <= n; i++)
    {
      for (j = i - 1; j >= 0; j--)
      {
        if (dp[i])
          break;
        if (!dp[j])
          continue;

        // cout << s.substr(j, i - j) << " " << endl;
        if (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
        {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};

int main(void)
{
  string s1 = "leetcode";
  vector<string> word1 = {"leet", "code"};

  cout << Solution139().wordBreak(s1, word1) << endl;

  return 0;
}
