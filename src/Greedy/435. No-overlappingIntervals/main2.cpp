#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution435
{
private:
  // 按照区间的结尾排序
  // 每次选择结尾最早的，且和前一个区间不重叠的区间
  //
  static bool cmp(const vector<int> &a, const vector<int> &b)
  {
    if (a[1] != b[1])
      return a[1] < b[1];
    return a[0] < b[0];
  }

public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    if (intervals.size() == 0 || intervals.size() == 1)
      return 0;

    // 先按区间大小排序
    sort(intervals.begin(), intervals.end(), cmp);

    // 贪心策略：结尾越小，留给了后面越大的空间，后面越有可能容纳更多区间
    int res = 1;
    int pre = 0; // 遍历后面的区间时，需要和前面的区间进行比较，这个变量就是用来存储前面所需要比较的区间
    for (int i = 1; i < intervals.size(); i++)
    {
      if (intervals[i][0] >= intervals[pre][1])
      {
        res++;
        pre = i;
      }
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
