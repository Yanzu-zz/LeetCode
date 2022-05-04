#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution1823_2
{
public:
  int findTheWinner(int n, int k)
  {
    queue<int> q;

    for (int i = 1; i <= n; i++)
      q.emplace(i);

    // 模拟每轮输的人出队
    while (q.size() > 1)
    {
      // 注意这里是执行 k-1 次操作，因为最后一个元素是要出队的
      for (int i = 1; i < k; i++)
      {
        q.emplace(q.front());
        q.pop();
      }

      q.pop();
    }

    return q.front();
  }
};

int main(void)
{
  cout << Solution1823().findTheWinner(5, 2) << endl;

  return 0;
}
