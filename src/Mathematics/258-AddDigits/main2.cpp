#include <iostream>
#include <vector>

using namespace std;

class Solution258
{
public:
  // 数学 f(x*10 + y) = f(x*9 + (x+y)) = f(x+y)
  int addDigits(int num)
  {
    return (num - 1) % 9 + 1;
  }
};

int main(void)
{

  return 0;
}
