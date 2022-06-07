#include <iostream>
#include <vector>

using namespace std;

class Solution875
{
public:
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int n = piles.size();
    int l = 1, r = INT_MIN;
    // 寻找左右边界
    for (int i = 0; i < n; i++)
      r = piles[i] > r ? piles[i] : r;

    // k 初始化为 最大值，是因为当只有一次吃 最大值 个香蕉时才能符合题意，那么 l 就会一路变大到等于 r，那么此时就不用算了
    int k = r;
    // 开始二分
    while (l < r)
    {
      int speed = l + (r - l >> 1);

      // 验证当前 speed 是否能符合题意
      long tmp = 0;
      for (int i = 0; i < n; i++)
        tmp += (piles[i] + speed - 1) / speed; // 向上取整

      // 速度太慢了，加快左边界
      if (tmp > h)
      {
        l = speed + 1;
      }
      // 速度符合题意，但可能会有更快的 speed，继续缩减右边界查找
      else
      {
        k = speed;
        // 因为此时 最小速度 一定小于或等于 speed，因此将右边界调整为 speed 而不是 speed - 1
        r = speed;
      }
    }

    return k;
  }
};

int main()
{

  return 0;
}