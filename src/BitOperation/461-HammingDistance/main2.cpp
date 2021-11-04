#include <iostream>

using namespace std;

class Solution461
{
public:
  int hammingDistance(int x, int y)
  {
    int s = x ^ y, ret = 0;
    while (s)
    {
      s &= s - 1;
      ret++;
    }
    return ret;
  }
};

int main()
{
  int x1 = 1, y1 = 4;
  cout << Solution461().hammingDistance(x1,y1) << endl;

  return 0;
}