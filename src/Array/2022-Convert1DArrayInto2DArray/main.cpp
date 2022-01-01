#include <iostream>
#include <vector>

using namespace std;

class Solution2022
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    int len = original.size();
    int cnt = 0;
    vector<vector<int>> res(m, vector<int>(n));
    // 如果需要转化的数组数量对不上，则不可能成功转换
    if (m * n != len)
      return vector<vector<int>>();

    // 开始转化
    for (int i = 0; i < len; i++)
    {
      // 确定当前元素应该是转化后的第几行，以及第几行里面的第几个元素
      int rowIdx = i / n;
      int colIdx = i % n;

      res[rowIdx][colIdx] = original[i];
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
