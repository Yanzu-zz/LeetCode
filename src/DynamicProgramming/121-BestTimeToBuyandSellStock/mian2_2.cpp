#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * dp解法：循环每个变量，同时记录到目前为止遇到的最小值，
 * 每次都用当前遍历到的元素与记录的最小值相减，得到新的最大利润就更新
 */
class Solution121
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int maxProfit = 0, min_val = prices[0];

    for (int i = 1; i < n; i++)
    {
      maxProfit = max(maxProfit, prices[i] - min_val);
      min_val = min(min_val, prices[i]);
    }

    return maxProfit;
  }
};

int main(void)
{
  vector<int> arr1 = {7, 1, 5, 3, 6, 4};
  vector<int> arr2 = {7, 6, 5, 4, 3, 2, 1};
  vector<int> arr3 = {2, 4, 1};

  cout << Solution121().maxProfit(arr1) << endl;
  cout << Solution121().maxProfit(arr2) << endl;
  cout << Solution121().maxProfit(arr3) << endl;

  return 0;
}
