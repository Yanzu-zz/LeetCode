#include <iostream>
#include <vector>

using namespace std;

class Solution693
{
public:
  bool hasAlternatingBits(int n)
  {
    // 注意范围，这里需要用 long，因为 INT_MAX + 1 会溢出
    // 如果 n 符合条件，则执行 x 后就为 0000····01111111
    long x = n ^ (n >> 1);
    // 此时 x+1 就等于 0000···10000000，然后与 x and 一下就为 0
    // 如果不是符合条件的就不会得 0
    return (x & (x + 1)) == 0;
  }
};

int main(void)
{

  return 0;
}
