#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution373
{
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    int m = nums1.size(), n = nums2.size();

    auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b)
    {
      return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };

    // 小根堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    vector<vector<int>> res;

    // 将所有可能的组合都加入小根堆中
    int limit = min(k, m);
    for (int i = 0; i < limit; i++)
      pq.emplace(i, 0);

    // 然后从中选取 top k 个
    while (k-- > 0 && !pq.empty())
    {
      auto [x, y] = pq.top();
      pq.pop();

      res.emplace_back(initializer_list<int>{nums1[x], nums2[y]});

      if (y + 1 < n)
        pq.emplace(x, y + 1);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
