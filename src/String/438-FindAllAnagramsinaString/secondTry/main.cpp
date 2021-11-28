#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    int n = s.size(), m = p.size();
    if (m > n)
      return {};

    vector<int> res;
    // 定义两个哈希表来表示当前 p 长度的 s 字符子串是否是 p 的异位词
    vector<int> pCnt(26, 0);
    vector<int> sCnt(26, 0);

    // 先统计 m 个字符长度
    for (int i = 0; i < n; i++)
    {
      // pCnt 算完就固定住了，不需要再改了，后面需要用到它就是用来比较的
      pCnt[p[i] - 'a']++;
      sCnt[s[i] - 'a']++;
    }
    // 如果相同的话表示前 m 个字符就是 p 的异位词，此时我们把索引 0 加进结果数组
    if (pCnt == sCnt)
      res.push_back(0);

    // 下面就是对后面的词进行比较了
    for (int i = m; i <= n - m; i++)
    {
      // 先把前面的一个词给去掉
      sCnt[s[i - m] - 'a']--;
      // 然后把最新的词给加进来
      sCnt[s[i] - 'a']++;

      // 此时再判断是否相等，是的话就是异位词
      if (pCnt == sCnt)
        res.push_back(i - m + 1);
    }

    return res;
  }
};

int main()
{

  return 0;
}