#include <iostream>
#include <vector>

using namespace std;

class Solution829
{
public:
  int consecutiveNumbersSum(int n)
  {
    int len = 2 * n, res = 0;
    // 条件 ②
    for (int i = 1; i * i < len; i++)
      // 条件 ① 和 ③
      if (((n << 1) % i == 0) && ((n << 1) / i - i + 1) % 2 == 0)
        res++;

    return res;
  }
};

int main()
{

  return 0;
}