#include <iostream>
#include <vector>

using namespace std;

/**
 * dp 解法配合三指针
 * 由于最小的丑数是 1，因此 dp[1]=1。
 * 如何得到其余的丑数呢？定义三个指针 p1, p2, p3，表示下一个丑数是当前指针指向的丑数乘以对应的质因数。初始时，三个指针的值都是 1
 * 当2≤i≤n时，令 dp[i]=min（dp[p2]]×2，dp[p3]×3，dp[5]×5），
 * 然后分别比较dp[i]和dp[p2]，dp[p3，dp[p5]是否相等，如果相等则将对应的指针加1
 */
class Solution264
{
public:
  int nthUglyNumber(int n)
  {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    int p2 = 1, p3 = 1, p5 = 1;
    int num2, num3, num5;
    for (int i = 2; i <= n; i++)
    {
      // dp 转移
      num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
      dp[i] = min(min(num2, num3), num5);

      // 移动指针
      if (dp[i] == num2)
        p2++;
      if (dp[i] == num3)
        p3++;
      if (dp[i] == num5)
        p5++;
    }

    return dp[n];
  }
};

int main(void)
{
  int n1 = 10;
  int n2 = 1;
  int n3 = 20;

  cout << Solution264().nthUglyNumber(n1) << endl;
  cout << Solution264().nthUglyNumber(n2) << endl;
  cout << Solution264().nthUglyNumber(n3) << endl;

  return 0;
}
