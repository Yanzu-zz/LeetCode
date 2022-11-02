#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
  vector<int> bestCoordinate(vector<vector<int>> &towers, int radius)
  {
    int mx = 0;
    vector<int> res = {0, 0};

    // 暴力枚举每一个点位，查看那个点信号最好
    for (int i = 0; i < 51; i++)
    {
      for (int j = 0; j < 51; j++)
      {
        int currSignalSum = 0;

        for (auto e : towers)
        {
          // 计算当前点位（i,j）到当前信号塔的距离
          double d = sqrt((i - e[0]) * (i - e[0]) + (j - e[1]) * (j - e[1]));
          // 若在范围信号内，则加权
          if (d <= radius)
            currSignalSum += e[2] / (1 + d);
        }

        // 然后比较大小
        if (mx < currSignalSum)
        {
          mx = currSignalSum;
          res = {i, j};
        }
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
