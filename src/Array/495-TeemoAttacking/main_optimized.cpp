#include <iostream>
#include <vector>

using namespace std;

class Solution495
{
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration)
  {
    timeSeries.push_back(1e8);
    int n = timeSeries.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
      if (timeSeries[i] + duration < timeSeries[i + 1])
        res += duration;
      else
        res += timeSeries[i + 1] - timeSeries[i];
    }

    return res;
  }
};

int main()
{

  return 0;
}