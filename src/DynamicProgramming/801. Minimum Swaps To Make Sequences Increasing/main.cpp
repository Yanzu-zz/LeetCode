#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minSwap(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    // dp[i][0] 表示 nums1和nums2 在 i 这个位置不交换
    // dp[i][1] 表示 nums1和nums2 在 i 这个位置交换，则次数相应增加
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = 1;

    for (int i = 1; i < n; i++)
    {
      // 获取相应位置的值，以便下面的对比
      int a1 = nums1[i - 1], a2 = nums1[i];
      int b1 = nums2[i - 1], b2 = nums2[i];

      // 情形 1
      if ((a1 < a2 && b1 < b2) && (b1 < a2 && a1 < b2))
      {
        // 如果i【不互换】，则i-1可【互换】也可【不互换】
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
        // 如果i【互换】，则i-1可【互换】也可【不互换】
        dp[i][1] = dp[i][0] + 1;
      }
      else if (a1 < a2 && b1 < b2)
      {
        dp[i][0] = dp[i - 1][0];     // 如果i【不互换】，则i-1必须【不互换】
        dp[i][1] = dp[i - 1][1] + 1; // 如果i【互换】，则i-1必须【互换】
      }
      else
      {
        dp[i][0] = dp[i - 1][1];     // 如果i【不互换】，则i-1必须【互换】
        dp[i][1] = dp[i - 1][0] + 1; // 如果i【互换】，则i-1必须【不互换】
      }
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
  }
};

int main(void)
{

  return 0;
}
