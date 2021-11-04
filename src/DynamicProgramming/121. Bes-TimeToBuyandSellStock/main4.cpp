#include <iostream>
#include <vector>

using namespace std;

class Solution121_4
{
public:
  int maxProfit(vector<int> &prices)
  {
    // 维护一个从前到后记录到当前位置最小的数的数组
    // 一个从后往前记录当前位置最大的数
    // 然后再循环一次，在每个位置都以最大数组-最小数组，记录最大值
    int n = prices.size(), ret = 0;
    vector<int> minVal(n, INT_MIN); // 最小
    vector<int> maxVal(n, INT_MAX); // 最大

    minVal[0] = prices[0];
    for (int i = 1; i < n; i++)
      minVal[i] = min(minVal[i - 1], prices[i]);

    maxVal[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
      maxVal[i] = max(maxVal[i + 1], prices[i]);
      ret = max(ret, maxVal[i] - minVal[i]);
    }

    return ret;
  }
};

int main(void)
{

  return 0;
}
