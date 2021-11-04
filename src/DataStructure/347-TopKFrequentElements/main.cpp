#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution347
{
public:
  // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
  static bool cmp(pair<int, int> &m, pair<int, int> &n)
  {
    // 根据元素出现的次数大小排序（即.second）
    return m.second > n.second;
  }

  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> occurrences;
    for (auto &v : nums) // 统计各元素出现的次数
      occurrences[v]++;

    // 创建小顶堆并遍历整个元素出现次数哈希表
    // 最终的小顶堆就是题目所求的 top k frequencies elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
    for (auto &[num, count] : occurrences)
    {
      if (q.size() == k) // 堆满了的话需要和堆顶元素做判断
      {
        if (q.top().second < count) // 出现的此处要比当前堆顶元素（即堆中出现次数最少的元素）相比
        {
          q.pop();
          q.emplace(num, count);
        }
      }
      else // 堆没满的话直接加进来就好
      {
        q.emplace(num, count);
      }
    }

    vector<int> res;
    while (!q.empty())
    { // 接下来把堆中元素都拿出来即可（题目不看元素顺序）
      res.emplace_back(q.top().first);
      q.pop();
    }

    return res;
  }
};

int main()
{

  return 0;
}