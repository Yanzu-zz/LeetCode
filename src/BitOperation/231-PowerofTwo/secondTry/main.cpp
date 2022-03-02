#include <iostream>
#include <vector>

using namespace std;

class Solution231
{
public:
  bool isPowerOfTwo(int n)
  {
    int count = 0;

    // 负整数不可能是 2的次幂
    while (n > 0 && count < 2)
    {
      if (n & 1)
        count++;
      n >>= 1; // 算数右移会将 n 向 0 靠近
    }

    return count == 1;
  }
};

int main(void)
{

  return 0;
}
