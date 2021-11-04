#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>
#include <cmath>

using namespace std;

class Solution279
{
public:
  int numSquares(int n)
  {
    if (n == 0)
      return 0;

    // 用来判断是否实现完全平方数的队列
    // 第一个int为减剩下的数，第二个为到这个数所花的次数
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));

    vector<bool> visited(n + 1, false);
    visited[n] = true;

    // 当队列中还有元素时继续下一步
    while (!q.empty())
    {
      // 获取此轮循环需要操作的数
      int minusNum = q.front().first;
      int curStep = q.front().second;
      q.pop();

      int t;
      // 当某个数的完全平方数大于当前计算的数时，可以退出循环了
      // for (int i = 1; minusNum >= i * i; i++)
      for (int i = (int)sqrt(minusNum); i > 0; i--)
      {
        t = minusNum - i * i;
        if (t == 0) // 当计算到结果 0 时，就算到所求步骤了
          return curStep + 1;

        if (!visited[t])
        {
          q.push(make_pair(t, curStep + 1));
          visited[t] = true;
        }
      }
    }
    // 因为有 1 的存在，所以不挂什么数都能有返回结果，故这里就不用多返回了
    throw invalid_argument("No Solution.");
  }
};

int main()
{
  cout << Solution279().numSquares(12) << endl;
  cout << Solution279().numSquares(13) << endl;

  return 0;
}