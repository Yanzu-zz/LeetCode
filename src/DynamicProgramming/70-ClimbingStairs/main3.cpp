#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 数学解法
 */
class Solution70
{
public:
  int climbStairs(int n)
  {
    double sqrt5 = sqrt(5);
    double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    
    return (int) round(fibn / sqrt5);
  }
};

int main(void)
{
  int n1 = 3;
  int n2 = 5;

  cout << Solution70().climbStairs(n1) << endl;
  cout << Solution70().climbStairs(n2) << endl;

  return 0;
}
