#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int reachNumber(int target)
  {
    int n = target < 0 ? -target : target;

    int currStep = 0, sum = 0;
    // 直到num值大于等于t，并且num减t是偶数，才结束while循环
    while (sum < n || (sum - n) % 2 == 1)
      sum += ++currStep;

    return currStep;
  }
};

int main(void)
{

  return 0;
}
