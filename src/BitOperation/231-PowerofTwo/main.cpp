#include <iostream>
#include <vector>

using namespace std;

/**
 * 解决思想：位运算
 * 我们把2的大部分幂的二进制都写下来，发现它只会有一个位置上有1，其它都是0
 * 那么我们就简单利用这个性质来判断 n 是否为 2 的幂
 * 
 * 时间复杂度：O(logn)
 */
class Solution231
{
public:
  bool isPowerOfTwo(int n)
  {
    int oneNum = 0;

    while (n > 0 && oneNum <= 1)
    {
      if (n & 1)
        oneNum++;
      n >>= 1;
    }

    return oneNum == 1;
  }
};

int main(void)
{
  int n1 = 4;
  int n2 = 15;
  int n3 = 1024;

  cout << Solution231().isPowerOfTwo(n1) << endl;
  cout << Solution231().isPowerOfTwo(n2) << endl;
  cout << Solution231().isPowerOfTwo(n3) << endl;

  return 0;
}
