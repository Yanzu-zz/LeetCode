#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
  int countSubstrings(string s)
  {
    int n = s.size(), res = 0;
    bool dp[n][n];
    for (int i = 0; i < n; i++)
      memset(dp[i], false, sizeof(dp[i]));

    for (int j = 0; j < n; j++)
    {
      for (int i = 0; i < n; i++)
      {
        if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
        {
          dp[i][j] = true;
          res++;
        }
      }
    }

    return res;
  }
};

int main()
{

  return 0;
}