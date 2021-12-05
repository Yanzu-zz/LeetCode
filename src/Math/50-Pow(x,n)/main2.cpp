#include <iostream>
#include <vector>

using namespace std;

class Solution50_2
{
private:
  double quickMul(double x, long long n)
  {
    double res = 1, base = x;

    // 快速幂，具体看笔记
    while (n > 0)
    {
      if (n & 1)
        res *= base;

      base *= base;
      n >>= 1;
    }

    return res;
  }

public:
  double myPow(double x, int n)
  {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
  }
};

int main()
{

  return 0;
}