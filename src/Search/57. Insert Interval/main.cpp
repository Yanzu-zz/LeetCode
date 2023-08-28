#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
  {
    int n = intervals.size();
    vector<vector<int>> ret;
    if (n == 0)
    {
      ret.push_back(newInterval);
      return ret;
    }

    // 二分插入 newInterval
    int l = 0, r = n;
    while (l < r)
    {
      int mid = l + ((r - l) >> 1);
      if (intervals[mid][0] < newInterval[0])
        l = mid + 1;
      else
        r = mid;
    }

    intervals.insert(intervals.begin() + l, newInterval);
    n++;

    // 然后再将原数组重新 merge一次
    for (int i = 0; i < n;)
    {
      int l = intervals[i][0];
      int r = intervals[i][1];

      int j = i + 1;
      while (j < n && r >= intervals[j][0])
      {
        r = max(r, intervals[j][1]);
        j++;
      }

      ret.push_back({l, r});
      i = j;
    }

    return ret;
  }
};

int main(void)
{

  return 0;
}
