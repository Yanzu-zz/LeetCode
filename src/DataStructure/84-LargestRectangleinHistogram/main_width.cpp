#include <iostream>
#include <vector>

using namespace std;

class Solution84
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int ret = 0;
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
      int minHeight = INT_MAX;
      // 从当前位置往右延伸面积，面积的高为 i~j 中最矮的高度，宽度为 j-i+1
      for (int j = i; j < n; j++)
      {
        minHeight = min(minHeight, heights[j]);
        ret = max(ret, (j - i + 1) * minHeight);
      }
    }

    return ret;
  }
};

int main(void)
{

  return 0;
}
