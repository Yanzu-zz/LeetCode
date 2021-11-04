#include <iostream>
#include <vector>

using namespace std;

/**
 * 解决思想：打表法
 * 既然是固定的判断2的幂，我们提前获取到题目范围内 2 的幂，然后面向测试用例编程即可（笑
 */
class Solution231
{
public:
  bool isPowerOfTwo(int n)
  {
    switch (n)
    {
      case 1:
      case 2:
      case 4:
      case 8:
      case 16:
      case 32:
      case 64:
      case 128:
      case 256:
      case 512:
      case 1024:
      case 2048:
      case 4096:
      case 8192:
      case 16384:
      case 32768:
      case 65536:
      case 131072:
      case 262144:
      case 524288:
      case 1048576:
      case 2097152:
      case 4194304:
      case 8388608:
      case 16777216:
      case 33554432:
      case 67108864:
      case 134217728:
      case 268435456:
      case 536870912:
      case 1073741824:
        return true;
    }
    return false;
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
