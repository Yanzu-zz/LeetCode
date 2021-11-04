#include <iostream>
#include <vector>

using namespace std;

class Solution322_2
{
private:
  int findChangeWay(vector<int> &coins, int amount, vector<int> &memo)
  {
    if (amount < 0)
      return -1;
    if (amount == 0)
      return 0;

    // 如果之前计算出结果了的话，直接返回
    if (memo[amount - 1] != 0) // 这里 -1 是对应数组从0开始
      return memo[amount - 1];

    // 之前没有结果就计算
    int min = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
      int res = findChangeWay(coins, amount - coins[i], memo);
      if (res >= 0 && res < min)
        min = res + 1; // 加1，是为了加上得到res结果的那个步骤中，兑换的一个硬币
    }

    memo[amount - 1] = (min == INT_MAX ? -1 : min);
    return memo[amount - 1];
  }

public:
  int coinChange(vector<int> &coins, int amount)
  {
    if (amount < 1)
      return 0;
    vector<int> memo(coins.size(), 0);
    return findChangeWay(coins, amount, memo);
  }
};

int main()
{

  return 0;
}