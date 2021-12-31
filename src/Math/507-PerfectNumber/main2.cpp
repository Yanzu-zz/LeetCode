#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution507
{
public:
  bool checkPerfectNumber(int num)
  {
    if (num <= 1)
      return false;

    int sum = 1; // 自动将真因子 1加上，这样就不用枚举到 num 本身了，只需要到 num/2 的范围即可
    int range = num / 2;

    for (int i = 2; i <= range; i++)
      if (num % i == 0)
        sum += i;

    return sum == num;
  }
};

int main(void)
{

  return 0;
}
