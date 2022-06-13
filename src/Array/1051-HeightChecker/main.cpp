#include <iostream>
#include <vector>

using namespace std;

class Solution1051
{
public:
  int heightChecker(vector<int> &heights)
  {
    int n = heights.size();
    int res = 0, m = INT_MIN;
    vector<int> arr(101, 0);

    // 计数排序
    for (int i = 0; i < n; i++)
    {
      int height = heights[i];
      arr[height]++;
      // 记录最大值
      m = m < height ? height : m;
    }

    // 然后开始统计
    int idx = 0;
    for (int i = 0; i <= m; i++)
    {
      int len = arr[i]; // 当前计数位置有值下面才循环
      for (int j = 0; j < len; j++)
        if (heights[idx++] != i) // 如果找到一个不在正确位置的元素的话，最终结果+1
          res++;
    }

    return res;
  }
};

int main()
{

  return 0;
}