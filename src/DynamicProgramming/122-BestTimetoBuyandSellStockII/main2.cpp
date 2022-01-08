#include <iostream>
#include <vector>

using namespace std;

class Solution122
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int res = 0;

    for (int i = 1; i < n; i++)
      // 策略是所有上涨交易日都买卖（赚到所有利润），所有下降交易日都不买卖（永不亏钱）
      res += max(0, prices[i] - prices[i - 1]);

    return res;
  }
};

int main(void)
{

  return 0;
}
