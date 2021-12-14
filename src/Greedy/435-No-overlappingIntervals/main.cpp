#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution435
{
private:
  static bool cmp(const vector<int> &a, const vector<int> &b)
  {
    if (a[0] != b[0])
      return a[0] < b[0];
    return a[1] < b[1];
  }

public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    if (intervals.size() == 0 || intervals.size() == 1)
      return 0;

    // 先按区间大小排序
    sort(intervals.begin(), intervals.end(), cmp);

    // memo[i] 表示使用 intervals[0...i] 的区间能构成的最长不重叠区间序列
    vector<int> memo(intervals.size(), 1);
    int res = 0;
    for (int i = 1; i < intervals.size(); i++)
    {

      for (int j = 0; j < i; j++)
        // 如果当前区间的开头比前面的结尾还大，则说明这两个区间不重叠
        if (intervals[i][0] >= intervals[j][1])
          memo[i] = max(memo[i], 1 + memo[j]);
      res = max(memo[i], res);
    }

    return intervals.size() - res;
  }
};

int main(void)
{
  vector<vector<int>> arr1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  vector<vector<int>> arr2 = {{1, 2}, {1, 2}, {1, 2}};

  cout << Solution435().eraseOverlapIntervals(arr1) << endl;
  cout << Solution435().eraseOverlapIntervals(arr2) << endl;

  return 0;
}
