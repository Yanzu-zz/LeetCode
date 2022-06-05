#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Solution
{
private:
  mt19937 gen{random_device{}()}; // mt19937 生成伪随机数算法，循环节为 2^19937-1
  uniform_real_distribution<double> dis;
  double xc, yc, r; // 圆中心点 (xc, yc) 以及 半径r

public:
  Solution(double radius, double x_center, double y_center) : dis(-radius, radius), r(radius), xc(x_center), yc(y_center) {}

  vector<double> randPoint()
  {
    while (true)
    {
      // 生成两个小偏量
      double x = dis(gen), y = dis(gen);
      // 接着验证是否在圆内
      if (x * x + y * y <= r * r)
        return {xc + x, yc + y};
    }
  }
};

int main()
{

  return 0;
}