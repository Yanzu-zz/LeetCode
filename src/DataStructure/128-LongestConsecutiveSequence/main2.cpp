#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution128_2
{
public:
  unordered_map<int, int> uf, cnt;

  int find(int i)
  {
    return i == uf[i] ? i : uf[i] = find(uf[i]);
  }

  int merge(int x, int y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
      return cnt[x];
    uf[y] = x;

    // 更新合并之后的联通分量的元素个数
    cnt[x] += cnt[y];
    return cnt[x];
  }

  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 1)
      return n;

    for (int i : nums)
    {
      uf[i] = i;
      cnt[i] = 1;
    }

    int ret = 1;
    for (int i : nums)
      if (i != INT_MAX && uf.count(i + 1))
        ret = max(ret, merge(i, i + 1));

    return ret;
  }
};

int main(void)
{

  return 0;
}
