#include <iostream>
#include <vector>

using namespace std;

/**
 * 解决思想：位运算
 * 与 1 不同的是，我们直接用系统内置的 __builtin_popcount 函数即可
 */
class Solution231
{
public:
  bool isPowerOfTwo(int n)
  {
    return n > 0 ? __builtin_popcount(n) == 1 : false;
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
