#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution522
{
public:
  // 将字符串数组按长度升序排序
  static bool cmp(string a, string b)
  {
    if (a.size() == b.size())
      return a < b;

    return a.size() > b.size();
  }

  bool judge(string a, string b)
  {
    int len1 = a.size(), len2 = b.size();
    if (len1 == len2)
      return a == b;

    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
      if (a[i] == b[j])
        i++;

      j++;
    }

    return i == len1;
  }

  int findLUSlength(vector<string> &strs)
  {
    sort(strs.begin(), strs.end(), cmp);

    int n = strs.size(), len = strs[0].size();
    bool find = false;

    for (int i = 0; i < n; i++)
    {
      len = strs[i].size();
      bool special = true;
      for (int j = 0; j < n; j++)
      {
        // 同一个字符串就不对比
        if (i == j)
          continue;

        if (strs[j].size() < len)
          break;

        if (judge(strs[i], strs[j]))
        {
          special = false;
          break;
        }
      }

      // 找到了结果，剪枝
      if (special)
      {
        find = true;
        break;
      }
    }

    return find ? len : -1;
  }
};

int main(void)
{

  return 0;
}
