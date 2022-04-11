#include <iostream>
#include <vector>

using namespace std;

class Solution357_2
{
public:
  int countNumbersWithUniqueDigits(int n)
  {
    // 终极打表法
    int res[10] = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851};

    return res[n];
  }
};

int main(void)
{

  return 0;
}
