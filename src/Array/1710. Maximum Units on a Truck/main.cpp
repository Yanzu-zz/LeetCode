#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
  {
    // 单位数量最大的优先防止到卡车上
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &box1, vector<int> &box2)
         { return box1[1] > box2[1]; });

    int res = 0, n = boxTypes.size();
    for (int i = 0; i < n && truckSize > 0; i++)
    {
      int currBoxCnt = boxTypes[i][0];
      // 如果卡车剩余空位比当前 box 多，直接全搬上车
      if (truckSize >= currBoxCnt)
      {
        res += currBoxCnt * boxTypes[i][1];
        truckSize -= currBoxCnt;
      }
      else
      {
        res += truckSize * boxTypes[i][1];
        truckSize = 0;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
