#include <iostream>
#include <vector>

using namespace std;

class Solution693
{
public:
  bool hasAlternatingBits(int n)
  {
    bool flag = n & 1;

    // 判断是否交替出现 0和1
    while (n)
    {
      n >>= 1;
      if ((n & 1) == flag)
        return false;
      flag = n & 1;
    }

    return true;
  }
};

int main(void)
{

  return 0;
}
