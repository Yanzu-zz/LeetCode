#include <iostream>
#include <vector>

using namespace std;

class Solution326_2
{
public:
  bool isPowerOfThree(int n)
  {
    while (n && n % 3 == 0)
      n /= 3;
    return n == 1;
  }
};

int main(void)
{

  return 0;
}
