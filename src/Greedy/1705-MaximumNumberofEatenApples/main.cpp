#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

class Solution1705
{
public:
  int eatenApples(vector<int> &apples, vector<int> &days)
  {
    int n = apples.size();
    int res = 0, time = 0; // time 表示当前到了第几天
    // 优先队列（小根堆），格式为：<当前苹果的保质期能到第几天，苹果数量>
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // 下面开始贪心计算最多能吃到多少个苹果（每天最多一个）
    while (time < n || !pq.empty())
    {
      // 每到新的一天就检查当前堆顶苹果是否腐烂不能吃了，是的话就将其出列
      while (!pq.empty() && pq.top().first < time)
        pq.pop();

      // 如果今天生产的苹果数量不为 0，则加入小根堆中
      if (time < n && apples[time] != 0)
        pq.emplace(time + days[time] - 1, apples[time]); // 因为数组索引是从 0开始的，故我们记录 该组的腐烂天数时需要-1

      // 下面就是开始吃了
      if (!pq.empty())
      {
        // 获取堆顶元素
        auto [a, b] = pq.top();
        pq.pop();
        // 吃苹果
        b--;
        // 如果当前这一天次的苹果还没有腐烂且吃了一个还剩下，那就再次入堆
        if (a > time && b > 0)
          pq.emplace(a, b);

        res++; // 记录吃了多少个苹果
      }

      time++;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
