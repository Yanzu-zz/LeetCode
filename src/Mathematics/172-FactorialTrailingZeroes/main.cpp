#include <iostream>
#include <vector>

using namespace std;

class Solution172
{
public:
  int trailingZeroes(int n)
  {
    int res = 0;

    // 统计质因子有多少个 5 即可
    while (n)
    {
      res += n / 5;
      n /= 5;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
