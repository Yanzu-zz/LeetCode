#include <iostream>
#include <vector>

using namespace std;

class Solution780
{
public:
  bool reachingPoints(int sx, int sy, int tx, int ty)
  {
    // 逆推不能越界
    while (tx > 0 && ty > 0)
    {
      // 逆推过程中发现能推回 (sx, sy)
      if (tx == sx && ty == sy)
        return true;
      else if (tx > ty)
        tx -= max((tx - sx) / ty, 1) * ty; // 快速逼近 sx
      else
        ty -= max((ty - sy) / tx, 1) * tx; // 快速逼近 sy
    }

    // 如果循环结束还没得到 (sx, sy) 则表明不能达到题意
    return false;
  }
};

int main(void)
{

  return 0;
}
