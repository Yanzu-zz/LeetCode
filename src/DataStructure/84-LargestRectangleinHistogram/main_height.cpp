#include <iostream>
#include <vector>

using namespace std;

class Solution84
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    int ret = 0;

    for (int i = 0; i < n; i++)
    {
      // 本次计算面积的高度固定位 heights[i]
      // 宽度则为 两边高度不低于当前柱子 的个数
      int left = i, right = i;
      int height = heights[i];

      // 寻找左边最长能做宽度的距离
      while (left > 0 && heights[left - 1] >= height)
        left--;

      // 寻找右边边最长能做宽度的距离
      while (right < n - 1 && heights[right + 1] >= height)
        right++;

      // 计算当前循环轮次的矩形面积
      ret = max(ret, (right - left + 1) * height);
    }

    return ret;
  }
};

int main(void)
{

  return 0;
}
