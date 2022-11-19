#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int largestAltitude(vector<int> &gain)
  {
    int n = gain.size(), res = 0, curr = 0;

    // 找到最高海拔
    for (int i = 0; i < n; i++)
    {
      curr += gain[i];
      res = curr > res ? curr : res;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
