#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int intersectionSizeTwo(vector<vector<int>> &intervals)
  {
    int res = 2; // 最小交集为 2
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });

    int i = intervals.back()[0], j = i + 1;
    int n = intervals.size();
    for (int k = n - 2; k >= 0; k--)
    {
      int tmp1 = intervals[k][0], tmp2 = intervals[k][1];
      if (i <= tmp2 && tmp2 < j)
      {
        res++;
        j = i;
        i = tmp1;
      }
      else if (tmp2 < i)
      {
        res += 2;
        i = tmp1;
        j = i + 1;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
