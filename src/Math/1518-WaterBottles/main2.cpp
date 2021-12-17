#include <iostream>
#include <vector>

using namespace std;

class Solution1518
{
public:
  int numWaterBottles(int numBottles, int numExchange)
  {
    return numBottles + (numBottles - 1) / (numExchange - 1);
  }
};

int main(void)
{

  return 0;
}
