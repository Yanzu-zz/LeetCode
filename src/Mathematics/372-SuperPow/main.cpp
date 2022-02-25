#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution372
{
private:
  const int MOD = 1337;

  int pow(int x, int n)
  {
    int res = 1;
    while (n > 0)
    {
      if (n & 1)
        res = (long)res * x % MOD;
      x = (long)x * x % MOD;
      n >>= 1;
    }

    return res;
  }

public:
  int superPow(int a, vector<int> &b)
  {
    int n = b.size(), res = 1;

    // 从个位数开始 快速幂%MOD
    for (int i = n - 1; i >= 0; i--)
    {
      res = (long)res * pow(a, b[i]) % MOD;
      a = pow(a, 10);
    }

    return res;
  }
};

int main()
{

  return 0;
}