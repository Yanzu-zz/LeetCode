#include <iostream>
#include <vector>

using namespace std;

class Solution495
{
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration)
  {
    int n = timeSeries.size();
    int res = 0, expired = 0;
    for (int i = 0; i < n; i++)
    {
      if (timeSeries[i] > expired)
        res += duration;
      else
        res += timeSeries[i] + duration - expired;

      expired = timeSeries[i] + duration;
    }

    return res;
  }
};

int main()
{

  return 0;
}