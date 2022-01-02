#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int lastRemaining(int n)
  {
    int total = n;     // 当前还剩多少个元素
    int isLeft = 0;    // 用来控制当前删除元素的方向
    int a0 = 1, d = 1; // a0 数组首项，d 数组公差

    // 开始模拟
    while (total != 1)
    {
      // 奇数个数字情况
      if (total % 2 == 1)
      {
        a0 = a0 + d;
      }
      // 偶数个数字情况
      else
      {
        // 当前方向，若为 true 表示从左向右，反之相反
        bool orientation = (isLeft % 2 == 0);
        // 从左向右且元素个数为偶数，则首项需要被删除，故我们改变首项的值而不是删除它（节省时间）
        if (orientation)
          a0 = a0 + d;
        // 从右向左且元素个数为偶数，则首项不需要被删除，我们保持原样
        else
          a0 = a0;
      }

      // 不论当前奇偶数情况，每次删除元素结束后，公差和元素剩余个数都要变，还有方向也要
      d *= 2;     // 公差要*2
      total /= 2; // 元素总数变成一半
      isLeft++;   // 改变方向
    }

    return a0;
  }
};

int main(void)
{

  return 0;
}
