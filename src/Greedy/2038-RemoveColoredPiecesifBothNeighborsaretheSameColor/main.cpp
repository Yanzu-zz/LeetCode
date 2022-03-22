#include <iostream>
#include <vector>

using namespace std;

class Solution2038
{
public:
  bool winnerOfGame(string colors)
  {
    int res[2] = {0, 0};
    char currColor = ' ';
    int cnt = 0;

    // 记录能被删除的颜色元素数量（必须连续三个以上）
    for (char color : colors)
    {
      if (currColor != color)
      {
        currColor = color;
        cnt = 1;
      }
      else
      {
        cnt++;
        if (cnt >= 3)
          res[color - 'A']++;
      }
    }

    return res[0] > res[1];
  }
};

int main(void)
{

  return 0;
}
