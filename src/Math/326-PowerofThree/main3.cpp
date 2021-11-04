#include <iostream>
#include <vector>

using namespace std;

class Solution326_3
{
public:
  bool isPowerOfThree(int n)
  {
    return n > 0 && 1162261467 % n == 0;
  }
};

int main(void)
{

  return 0;
}
