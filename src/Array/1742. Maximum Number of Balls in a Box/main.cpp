#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int countBalls(int lowLimit, int highLimit)
  {
    int res = 1;
    vector<int> cnt(60, 0);

    for (int i = lowLimit; i <= highLimit; i++)
    {
      int val = i, idx = 0;
      while (val > 0)
      {
        idx += val % 10;
        val /= 10;
      }

      cnt[idx]++;
      res = cnt[idx] > res ? cnt[idx] : res;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
