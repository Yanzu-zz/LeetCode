#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution479
{
public:
  int largestPalindrome(int n)
  {
    // 当 n 位数时，最大的回文数能在 2*n 位数中找到 (n > 1)
    if (n == 1)
      return 9;

    // 然而我们只需要枚举回文数的左半部分构造出完整的回文数然后求余即可
    // 注意，该回文数是要两位数乘积求出的，像 9779 这种回文数没有两位数能乘积求出
    long upper = pow(10, n) - 1;
    // 由于一定能在
    for (long i = upper;; i--)
    {
      long p = i;
      // 构造回文数
      for (long t = i; t > 0; t /= 10)
        p = p * 10 + t % 10;

      // 用 x 来查看是否为构造出的回文数 p 的因子，是的话则表明 p 这个回文数能用 两位数乘积求出（其它 n 位数也同理）
      for (long x = upper; x * x >= p; x--)
        if (p % x == 0)
          return p % 1337;
    }

    return 0;
  }
};

int main(void)
{

  return 0;
}
