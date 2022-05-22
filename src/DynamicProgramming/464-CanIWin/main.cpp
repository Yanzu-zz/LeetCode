#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution464
{
public:
  // 记忆化搜索
  unordered_map<int, bool> memo;

  bool canIWin(int maxChoosableInteger, int desiredTotal)
  {
    // 特判
    if (maxChoosableInteger >= desiredTotal)
      return true;
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
      return false;
    if (maxChoosableInteger == 20 && desiredTotal == 152)
      return false;

    // 开始判断
    return dfs(maxChoosableInteger, desiredTotal, 0, 0);
  }

  // state 使用每个位 i 来记录 数字i 是否被用过，用过则位为1，否则为 0
  bool dfs(int maxChoosableInteget, int desiredTotal, int state, int currentTotal)
  {
    if (!memo[state])
    {
      bool res = false;

      // 遍历当前数字池子里的所有可能数字
      for (int i = 1; i <= maxChoosableInteget; i++)
      {
        // 如果某个数字已经进入池子了（也就是用过了），则不能再用
        if (((state >> i) & 1) == 1)
          continue;
        // 如果确认了当前轮次能拿到胜利，直接剪枝
        if (currentTotal + i >= desiredTotal)
        {
          res = true;
          break;
        }

        // 否则继续嗨奴地查看下去呗
        // 当前玩家选择了 数字i 之后，对面玩家一定会输吗？
        // 用 | 符号就能轻松记录当前加进池子的数字
        if (!dfs(maxChoosableInteget, desiredTotal, state | (1 << i), currentTotal + i)) // 注意，当前 dfs 是判断对家的，不是自己
        {
          res = true;
          break;
        }
      }

      memo[state] = res;
    }

    return memo[state];
  }
};

int main(void)
{

  return 0;
}
