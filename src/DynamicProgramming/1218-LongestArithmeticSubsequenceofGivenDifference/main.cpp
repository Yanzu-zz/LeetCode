#include <iostream>
#include <vector>

using namespace std;

class Solution1218
{
public:
  int longestSubsequence(vector<int> &arr, int difference)
  {
    int n = arr.size();
    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 1; i < n; i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (arr[i] - difference == arr[j])
        {
          dp[i] = max(dp[i], dp[j] + 1);
          break;
        }
      }
      res = max(res, dp[i]);
    }

    return res;
  }
};

int main()
{

  return 0;
}