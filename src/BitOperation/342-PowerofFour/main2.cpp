#include <iostream>
#include <vector>

using namespace std;

/**
 * 方法二：打表法
 *  这个方法的绝妙之处我就不多说了
 */
class Solution342
{
public:
  bool isPowerOfFour(int n)
  {
    switch (n)
    {
    case 1:
      return true;
    case 4:
      return true;
    case 16:
      return true;
    case 64:
      return true;
    case 256:
      return true;
    case 1024:
      return true;
    case 4096:
      return true;
    case 16384:
      return true;
    case 65536:
      return true;
    case 262144:
      return true;
    case 1048576:
      return true;
    case 4194304:
      return true;
    case 16777216:
      return true;
    case 67108864:
      return true;
    case 268435456:
      return true;
    case 1073741824:
      return true;
    default:
      return false;
    }
    return false;
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
