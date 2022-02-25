#include <iostream>
#include <vector>

using namespace std;

class Solution326_2
{
public:
  bool isPowerOfThree(int n)
  {
    long sum = 1;

    while (sum < n)
      sum *= 3;

    return sum == n;
  }
};

int main(void)
{

  return 0;
}
