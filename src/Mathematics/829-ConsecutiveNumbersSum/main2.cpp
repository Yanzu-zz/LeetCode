#include <iostream>
#include <vector>

using namespace std;

class Solution829
{
public:
  int consecutiveNumbersSum(int N)
  {
    int res = 0;
    for (int i = 1; N > 0; N -= i++)
      res += (N % i == 0);
    return res;
  }
};

int main()
{

  return 0;
}