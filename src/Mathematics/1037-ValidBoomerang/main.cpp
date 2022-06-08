#include <iostream>
#include <vector>

using namespace std;

class Solution1037
{
public:
  bool isBoomerang(vector<vector<int>> &points)
  {
    // 两个向量
    int v1_1 = points[1][0] - points[0][0], v1_2 = points[1][1] - points[0][1];
    int v2_1 = points[2][0] - points[0][0], v2_2 = points[2][1] - points[0][1];

    // 判断向量叉乘是否为 0 就知道是否三点共线
    return (v1_1 * v2_2) ^ (v1_2 * v2_1);
  }
};

int main()
{

  return 0;
}