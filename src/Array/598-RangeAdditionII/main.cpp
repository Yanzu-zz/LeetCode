#include <iostream>
#include <vector>

using namespace std;

class Solution598
{
public:
  int maxCount(int m, int n, vector<vector<int>> &ops)
  {
    int minA = m, minB = n;
    // 每次操作都是左上角区域从（0, 0）到（a, b）的矩形，必定重叠，所以找最小的a乘最小的b就行
    for (const auto &op : ops)
    {
      minA = min(minA, op[0]);
      minB = min(minB, op[1]);
    }

    return minA * minB;
  }
};

int main()
{

  return 0;
}