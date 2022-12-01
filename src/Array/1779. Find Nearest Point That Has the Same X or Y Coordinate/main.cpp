#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points)
  {
    int n = points.size(), minDis = INT_MAX, resCoordinate = -1;

    for (int i = 0; i < n; i++)
    {
      int currX = points[i][0], currY = points[i][1];
      // 符合条件的才能计算曼哈顿距离
      if (currX == x || currY == y)
      {
        int currDis = abs(currX - x) + abs(currY - y);

        if (currDis < minDis)
        {
          minDis = currDis;
          resCoordinate = i; // 返回的是最小的坐标在数组中的索引序号
        }
      }
    }

    return resCoordinate;
  }
};

int main(void)
{

  return 0;
}
