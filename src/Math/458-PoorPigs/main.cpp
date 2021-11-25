#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution458
{
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest)
  {
    int states = minutesToTest / minutesToDie + 1;
    int pigs = ceil(log(buckets) / log(states));
    return pigs;
  }
};

int main()
{

  return 0;
}