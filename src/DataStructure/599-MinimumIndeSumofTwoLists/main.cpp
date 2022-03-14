#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution599
{
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
  {
    int n = list1.size(), m = list2.size();
    int leastIdx = n + m;
    vector<string> res;
    unordered_map<string, int> mp;

    // 记录 list1 的元素索引
    for (int i = 0; i < n; i++)
      mp[list1[i]] = i;

    // 接着就是与 list2 对比
    for (int i = 0; i < m; i++)
    {
      if (!mp.count(list2[i]))
        continue;

      int j = mp[list2[i]];
      if (i + j < leastIdx) // 如果找到个更小的索引和
      {
        leastIdx = i + j;
        res.clear();
        res.emplace_back(list2[i]);
      }
      else if (i + j == leastIdx) // 如果有相同的索引和
      {
        res.emplace_back(list2[i]);
      }
      else // 如果 i 的值都大于当前记录过的最小索引和则表明后面不可能会有比当前记录的小的
      {
        break;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
