#include <iostream>
#include <vector>

using namespace std;

class Solution1217
{
public:
  int minCostToMoveChips(vector<int> &position)
  {
    int n = position.size();
    int evenNum = 0, oddNum = 0;
    for (int pos : position)
    {
      int tmp = pos % 2;

      evenNum += tmp & 1;
      oddNum += !(tmp & 0);
    }

    return min(evenNum, oddNum);
  }
};

int main(void)
{

  return 0;
}
