#include <iostream>
#include <vector>

using namespace std;

class Solution1518
{
public:
  int numWaterBottles(int numBottles, int numExchange)
  {
    int res = numBottles;

    while (numBottles >= numExchange)
    {
      // A: 表示若不能全部换完剩下的空酒瓶子数量
      // 表示用这些喝完了的空瓶子酒能换新的酒的数量
      int A = numBottles % numExchange;
      int B = numBottles / numExchange;
      res += B; // 只能换 B 个新的酒

      numBottles = A + B; // 下一轮准备换新的酒水的空瓶子数量
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
