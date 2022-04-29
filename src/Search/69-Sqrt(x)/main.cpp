#include <iostream>
#include <vector>

using namespace std;

class Solution69
{
public:
  int mySqrt(int x)
  {
    if (x == 1)
      return 1;

    int i = 1, len = x >> 1;
    // 大的数会越界
    for (; i <= len && (long long)i * i <= x; i++)
      ;

    return i - 1;
  }
};

int main(void)
{

  return 0;
}
