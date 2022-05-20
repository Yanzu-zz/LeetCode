#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution436
{
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals)
  {
    int n = intervals.size();
    map<int, int> mp; // 红黑树自动排序 starti
    vector<int> res;

    // 记录索引
    int idx = 0;
    for (auto &v : intervals)
      mp[v[0]] = idx++;

    // 然后就是二分查找 endi 最近的一个 starti，此时这个 starti 是大于等于它，在它右边第一个位置
    for (auto &v : intervals)
    {
      auto it = mp.lower_bound(v[1]);
      if (it != mp.end())
        res.emplace_back((*it).second); // .second 是记录下来的索引位置
      else
        res.emplace_back(-1);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
