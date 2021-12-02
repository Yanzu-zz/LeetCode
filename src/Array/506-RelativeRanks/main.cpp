#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution506
{
public:
  vector<string> findRelativeRanks(vector<int> &score)
  {
    int n = score.size();
    vector<pair<int, int>> idxArr(n);

    // 存入对应元素值的索引位置
    for (int i = 0; i < n; i++)
      idxArr.emplace_back(make_pair(score[i], i));
    // 然后排序（注意是从大到小
    sort(idxArr.rbegin(), idxArr.rend());

    // 接着就是处理返回数组了
    vector<string> res(n);
    string title[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    for (int i = 0; i < n; i++)
    {
      if (i < 3)
        res[idxArr[i].second] = title[i];
      else
        res[idxArr[i].second] = to_string(i + 1);
    }

    return res;
  }
};

int main()
{

  return 0;
}