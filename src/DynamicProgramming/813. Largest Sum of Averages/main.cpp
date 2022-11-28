#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  double largestSumOfAverages(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<vector<double>> dp(n + 1, vector<double>(k + 1));
    vector<double> prefix(n + 1);

    // 计算前缀和
    for (int i = 0; i < n; i++)
      prefix[i + 1] = prefix[i] + nums[i];

    // j = 1 情况，即只分一个组的情况
    for (int i = 1; i <= n; i++)
      dp[i][1] = prefix[i] / i;

    // j > 1的情况，也就是分多个组
    // 切分的组越多，求得的值越大
    for (int j = 2; j <= k; j++)
      for (int i = j; i <= n; i++)
        for (int x = j - 1; x < i; x++)
          dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));

    return dp[n][k];
  }
};

int main(void)
{

  return 0;
}
