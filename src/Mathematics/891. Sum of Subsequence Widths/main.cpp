#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int sumSubseqWidths(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    long res = 0;
    int MOD = (int)1e9 + 7, n = nums.size();
    vector<long> pow(n);
    pow[0] = 1;

    for (int i = 1; i < n; i++)
      pow[i] = (pow[i - 1] << 1) % MOD; // 初始化 2^n 的值

    // 开始计算
    for (int i = 0; i < n; i++)
      res = (res + (pow[i] - pow[n - i - 1]) * nums[i] % MOD) % MOD;

    return (int)res;
  }
};

int main(void)
{

  return 0;
}
