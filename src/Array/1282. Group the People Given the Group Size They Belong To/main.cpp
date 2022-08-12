#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1282
{
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes)
  {
    int n = groupSizes.size();
    // 用哈希表记下来索引，这个题目就很好解决了
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
      mp[groupSizes[i]].emplace_back(i);

    vector<vector<int>> res;
    // 题目保证一定有解
    for (auto kv : mp)
    {
      int count = kv.first, len = kv.second.size();
      int i = 0, curIdx = count;
      while (len > 0)
      {
        vector<int> tmp;
        for (; i < curIdx; i++)
          tmp.emplace_back(kv.second[i]);

        len -= count;
        curIdx += count;
        res.push_back(tmp);
      }
    }

    return res;
  }
};

int main(void)
{
  vector<int> a = {3, 3, 3, 3, 3, 1, 3};
  Solution1282().groupThePeople(a);

  return 0;
}
