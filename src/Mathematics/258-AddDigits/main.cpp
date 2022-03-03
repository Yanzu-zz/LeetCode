#include <iostream>
#include <vector>

using namespace std;

class Solution258
{
public:
  // 模拟，就是 while 一个循环把每位数都加起来直到该数小于 10 就返回。
  int addDigits(int num)
  {
    while (num >= 10)
    {
      int sum = 0;
      while (num)
      {
        sum += num % 10;
        num /= 10;
      }
      num = sum;
    }

    return num;
  }
};

int main(void)
{

  return 0;
}
