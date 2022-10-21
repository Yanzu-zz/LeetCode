#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StockSpanner
{
public:
  int idx;
  stack<pair<int, int>> stk;

  StockSpanner()
  {
    stk.emplace(-1, INT_MAX);
    idx = -1;
  }

  int next(int price)
  {
    idx++;
    while (price >= stk.top().second)
      stk.pop();

    // 计算有多少天是大于之前天数的
    int res = idx - stk.top().first;
    stk.emplace(idx, price);

    return res;
  }
};

int main(void)
{

  return 0;
}
