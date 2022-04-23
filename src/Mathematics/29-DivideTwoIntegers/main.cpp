#include <iostream>
#include <vector>

using namespace std;

class Solution29
{
private:
  int div(int dividend, int divisor)
  {
    if (dividend > divisor)
      return 0;

    int count = 1, num = divisor;
    // 使用 dividend - num 来防止 int 类型溢出
    while ((dividend - num) <= num)
    {
      num += num;     // 判断是否翻倍大于 dividend 变量
      count += count; // 记录当前结果
    }

    return div(dividend - num, divisor) + count;
  }

public:
  int divide(int dividend, int divisor)
  {
    if (dividend == 0)
      return 0;
    if (divisor == 1)
      return dividend;
    // 注意 INT_MIN == -INT_MAX + 1，直接转化 - INT_MIN 会溢出
    if (divisor == -1)
    {
      if (dividend > INT_MIN)
        return -dividend;
      return INT_MAX;
    }

    // 其中有一个负数才算是 isSign
    bool isSign = false;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
      isSign = true;
    int a = dividend < 0 ? dividend : -dividend;
    int b = divisor < 0 ? divisor : -divisor;

    int res = div(a, b);
    // 防止溢出
    if (!isSign)
      return res > INT_MAX ? INT_MAX : res;
    return -res;
  }
};

int main(void)
{

  return 0;
}
