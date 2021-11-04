#include <iostream>
#include <vector>

using namespace std;

class Solution441
{
public:
  int arrangeCoins(int n)
  {
    long l = 1, r = n;
    while (l < r)
    {
      long mid = l + (r - l + 1) / 2; // 中间位置，这里要+1的原因是到剩余两个元素时，尽量往大的元素靠，不然会死循环
      // 用我们很熟悉的等差数列公式来求值
      if (mid * (mid + 1) / 2 <= n)
        l = mid; // 如果中间值还小于 n 的话说明中间值还不够大，我们往右移
      else
        r = mid - 1; // 如果中间值大过 n 了，说明当前中间值太大了，我们往左移
    }                // 直到他们碰到了（l==r）就说明找到了值

    return (int)r;
  }
};

int main(void)
{
  cout << Solution441().arrangeCoins(5) << endl;
  cout << Solution441().arrangeCoins(8) << endl;

  return 0;
}
