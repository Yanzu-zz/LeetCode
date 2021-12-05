#include <iostream>
#include <vector>

using namespace std;

class Solution50
{
private:
  double quickMul(double x, long long n)
  {
    if (n == 0)
      return 1.0;

    // 递归获取 x^(n/2) 的值
    double sqrtXN = quickMul(x, n / 2);
    double result = sqrtXN * sqrtXN;

    // 如果当前 n 是偶数，则直接返回它的 x^(n/2)* x^(n/2) 即可
    // 若 n 是奇数，在算递归的时候会向下取整，故还需要乘多一次 x
    return n % 2 == 0 ? result : result * x;
  }

public:
  double myPow(double x, int n)
  {
    long long N = n;
    // 如果 n 是负数则将 x 倒过来后再进行快速幂
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
  }
};

int main()
{

  return 0;
}