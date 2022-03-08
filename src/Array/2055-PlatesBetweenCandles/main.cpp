#include <iostream>
#include <vector>

using namespace std;

class Solution2055
{
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
  {
    int n = s.size();
    // 记录当前位置左右最近蜡烛位置的索引
    vector<int> left(n, -1), right(n, -1);
    // 记录当前是第几个盘子，若当前为蜡烛，则赋值左边最近的盘子的数量值
    vector<int> preSum(n, 0);
    vector<int> res;

    // 记录
    left[0] = s[0] == '|' ? 0 : -1;
    for (int i = 1; i < n; i++)
    {
      if (s[i] == '|')
        left[i] = i;
      else
        left[i] = left[i - 1];
    }

    right[n - 1] = s[n - 1] == '|' ? n - 1 : -1;
    for (int i = n - 2; i >= 0; i--)
    {
      if (s[i] == '|')
        right[i] = i;
      else
        right[i] = right[i + 1];
    }

    // 接下来是前缀和数组记录当前是第几个盘子
    int plateNum = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '*')
        plateNum++;
      preSum[i] = plateNum;
    }

    // 下面开始计算结果
    for (int i = 0; i < queries.size(); i++)
    {
      int l = queries[i][0], r = queries[i][1];
      // 接着获取所给区间左右两边最近的蜡烛点位
      int leftCandle = -1, rightCandle = -1;
      // 注意不能越界
      if (right[l] <= r && left[r] >= l)
        leftCandle = right[l], rightCandle = left[r];

      // 然后就是计算
      int tmp = 0;
      if (leftCandle != -1 && rightCandle != -1)
        tmp = preSum[rightCandle] - preSum[leftCandle];
      res.emplace_back(tmp);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
