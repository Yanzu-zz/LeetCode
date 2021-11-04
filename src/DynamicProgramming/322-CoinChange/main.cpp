#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution322
{
private:
  int res = INT_MAX;
  // 使用递归的关键是知道递归函数是用来干什么的，从宏观的角度去理解递归。
  void findChangeWay(vector<int> &coins, int amount, int coinNums)
  {
    // 边界条件
    if (amount < 0)
    {
      return;
    }
    else if (amount == 0)
    {
      res = min(res, coinNums);
      return;
    }
    else
    {
      for (int i = coins.size() - 1; i >= 0; i--)
        findChangeWay(coins, amount - coins[i], coinNums + 1);
    }
  }

public:
  int coinChange(vector<int> &coins, int amount)
  {
    findChangeWay(coins, amount, 0);

    return res == INT_MAX ? -1 : res;
  }
};

int main()
{

  return 0;
}