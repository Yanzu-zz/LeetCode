#include <iostream>
#include <vector>

using namespace std;

/**
  方法一：二进制表示中 11 的位置
    如果 n 是 4 的幂，那么 n 的二进制表示中有且仅有一个 1，并且这个 1 出现在从低位开始的第偶数个二进制位上（这是因为这个 1 后面必须有偶数个 0）。这里我们规定最低位为第 0 位，例如 n=16 时，n 的二进制表示为
      (10000)2
    唯一的 1 出现在第 4 个二进制位上，因此 n 是 4 的幂。
    且这种只有 1 位是 1 的数字的上一位数字 n-1 的特点是头部是0其余位置全是1，所以我们用 n & n-1 来判断它确实为 4 的幂
    由于题目保证了 n 是一个 32 位的有符号整数，因此我们可以构造一个整数 mask，它的所有偶数二进制位都是 0，所有奇数二进制位都是 1。这样一来，我们将 n 和 mask 进行按位与运算，如果结果为 0，说明 nn 二进制表示中的 1 出现在偶数的位置，否则说明其出现在奇数的位置。
    根据上面的思路，mask 的二进制表示为：
      mask=(10101010101010101010101010101010) 2
    我们也可以将其表示成 16 进制的形式，使其更加美观：
      mask=(AAAAAAAA) 16
 */
class Solution342
{
public:
  bool isPowerOfFour(int n)
  {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
  }
};

int main(void)
{
  int n1 = 4;
  int n2 = 15;
  int n3 = 256;
  int n4 = 2;

  cout << Solution342().isPowerOfFour(n1) << endl;
  cout << Solution342().isPowerOfFour(n2) << endl;
  cout << Solution342().isPowerOfFour(n3) << endl;
  cout << Solution342().isPowerOfFour(n4) << endl;

  return 0;
}
