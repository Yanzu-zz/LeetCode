#include <iostream>
#include <vector>

using namespace std;

class Solution812_2
{
public:
  double largestTriangleArea(vector<vector<int>> &points)
  {
    double res = 0;
    for (auto &&p1 : points)
    {
      for (auto &&p2 : points)
      {
        for (auto &&p3 : points)
        {
          // 向量 A(i, j), B(x, y)，则 AB = (x - i, y - j)
          double x1 = p1[0];
          double x2 = p2[0] - x1;
          double x3 = p3[0] - x1;
          double y1 = p1[1];
          double y2 = p2[1] - y1;
          double y3 = p3[1] - y1;

          // 自己画个二阶行列式 叉乘 一下就是这个结果
          res = max(res, abs(x2 * y3 - x3 * y2) / 2);
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
