#include <iostream>
#include <vector>

using namespace std;

/**
 * 单调栈解法：维护一个单调递增的栈，与当前循环到的元素与栈顶元素相比较
 * 若：小于栈顶元素时，则 pop栈，并与下个栈元素相比，知道当前元素大雨栈顶元素或栈空，此时这个元素入栈
 * 大于当前栈顶元素则直接入栈
 * 在每次 pop栈 时与栈底元素相减比较取最大值
 * 值得注意的是，需要在 prices 数组后面放一个最小值，这样即使全是单调递增的数组最后也能得到正确的值（自己想想为什么）
 */
class Solution121
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int maxProfit = 0, curProfit;

    prices.emplace_back(INT_MIN); // 改变原数组，将一个最小的值置入数组最后（哨兵）
    vector<int> monotoneStack;
    monotoneStack.emplace_back(prices[0]); // 初始化栈

    for (int i = 1; i <= n; i++)
    {
      // 当前元素小于栈顶元素
      while (!monotoneStack.empty() && prices[i] < monotoneStack.back())
      {
        curProfit = monotoneStack.back() - monotoneStack.front();
        if (curProfit > maxProfit)
          maxProfit = curProfit;
        monotoneStack.pop_back();
      }

      monotoneStack.emplace_back(prices[i]);
    }

    return maxProfit;
  }
};

int main(void)
{
  vector<int> arr1 = {7, 1, 5, 3, 6, 4};
  vector<int> arr2 = {7, 6, 5, 4, 3, 2, 1};
  vector<int> arr3 = {2, 4, 1};
  vector<int> arr4 = {1, 2, 4};

  cout << Solution121().maxProfit(arr1) << endl;
  cout << Solution121().maxProfit(arr2) << endl;
  cout << Solution121().maxProfit(arr3) << endl;
  cout << Solution121().maxProfit(arr4) << endl;

  return 0;
}
