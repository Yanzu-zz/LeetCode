#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution279
{
private:
  vector<int> memo;

  // 记忆化搜索，从底下小数据量开始计算存储，接着到大数据量
  int go(int n)
  {
    if (n == 0)
      return 0;

    if (memo[n] != -1)
      return memo[n];

    int res = n;
    for (int i = 1; n >= i * i; i++)
      res = min(res, 1 + go(n - i * i));

    memo[n] = res;
    return res;
  }

public:
  int numSquares(int n)
  {
    memo = vector<int>(n + 1, -1);

    return go(n);
  }
};

int main(){
  cout << Solution279().numSquares(12) << endl;
  cout << Solution279().numSquares(13) << endl;

  return 0;
}