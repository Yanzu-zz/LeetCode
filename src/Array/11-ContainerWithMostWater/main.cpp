#include <iostream>
#include <vector>

using namespace std;

class Solution11
{
public:
  int maxArea(vector<int> &height)
  {
    int n = height.size();
    int i = 0, j = n - 1;
    int res = INT_MIN;

    // 不相遇则继续
    while (i < j)
    {
      bool moveSide = height[i] < height[j];
      // 这里的三元 ++ -- 就用的很秒，只有条件成立才会进行操作
      int curArea = (moveSide ? height[i++] : height[j--]) * (j - i + 1);

      res = max(res, curArea);
    }

    return res;
  }
};

int main()
{

  return 0;
}