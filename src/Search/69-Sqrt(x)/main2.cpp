#include <iostream>
#include <vector>

using namespace std;

class Solution69
{
public:
  int mySqrt(int x)
  {
    int res = 1;
    int l = 0, r = x;

    // 二分快速逼近
    while (l <= r)
    {
      int mid = l + (r - l >> 1);
      // 同样小心越界
      // 不想用 lon long 的话可以用 x/mid == mid 来判断
      if ((long long)mid * mid <= x)
      {
        res = mid;
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
