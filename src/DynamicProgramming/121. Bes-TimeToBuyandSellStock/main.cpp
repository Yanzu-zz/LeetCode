#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 暴力解法（超时）：循环每一个变量，在其后面找到比它大的最大值，接着相减，存起来最大的值即可
 */
class Solution121
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int i, j;
    int ret = 0;

    for (i = 0; i < n; i++)
      for (j = i + 1; j < n; j++)
        ret = max(ret, prices[j] - prices[i]);

    return ret;
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
