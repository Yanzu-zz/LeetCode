#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
  class Solution
  {
  public:
    int arrangeCoins(int n)
    {
      return (int)((sqrt(8.0 * n + 1) - 1) / 2);
    }
  };

  return 0;
}
