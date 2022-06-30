#include <iostream>
#include <vector>

using namespace std;

class Solution1175
{
public:
  int numPrimeArrangements(int n)
  {
    // 题目的本意是统计n以内素数的个数，答案由素数的全排列数乘上非素数的全排列数（阶乘）得到
    int MOD = (int)1e9 + 7;
    vector<int> primes(101, 0);
    vector<long> factorial(101);

    primes[0] = primes[1] = 0;
    factorial[0] = factorial[1] = 1L;
    for (int i = 2; i <= 100; i++)
    {
      // 计算阶乘
      factorial[i] = factorial[i - 1] * i % MOD;
      primes[i] = primes[i - 1] + isPrime(i);
    }

    return (int)(factorial[primes[n]] * factorial[n - primes[n]] % MOD);
  }

  bool isPrime(int x)
  {
    for (int i = 2; i * i <= x; i++)
    {
      if (x % i == 0)
        return false;
    }

    return true;
  }
};

int main(void)
{

  return 0;
}
