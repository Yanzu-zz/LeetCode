#include <iostream>
#include <vector>

using namespace std;

class Solution397
{
public:
  int integerReplacement(int n)
  {
    int res = 0;

    // 贪心
    while (n != 1)
    {
      if (n % 2 == 0)
      {
        res++;
        n /= 2;
      }
      else if (n % 4 == 1)
      {
        res += 2;
        n /= 2;
      }
      else
      {
        res += 2;
        if (n == 3)
          n = 1;
        else
          n = n / 2 + 1;
      }
    }

    return res;
  }
};

int main()
{

  return 0;
}