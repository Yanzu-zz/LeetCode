#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution786_2
{
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
  {
    int n = arr.size();
    // 自定义优先队列排序函数
    auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y)
    {
      return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    // 先将 n-1 个元素加进来（这其中一定有最小的 arr[0]/arr[n-1]
    for (int j = 1; j < n; j++)
      q.emplace(0, j);

    // 只需要 pop 掉 k-1 个最小分数，那么结束后优先队列第一个元素就是所求值
    for (int x = 0; x < k - 1; x++)
    {
      auto [i, j] = q.top();
      // 获取一次当前最小分数元素就 pop 一次
      q.pop();

      if (i + 1 < j) // 防止加入相同索引值判断
        q.emplace(i + 1, j);
    }

    auto [i, j] = q.top();
    return {arr[i], arr[j]};
  }
};

int main()
{

  return 0;
}