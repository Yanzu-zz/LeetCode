#include <iostream>
#include <vector>

using namespace std;

class Solution438
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    int n = s.size(), m = p.size();
    if (m > n)
      return {};

    vector<int> res;
    vector<int> pCnt(26, 0);
    vector<int> sCnt(26, 0);
    for (int i = 0; i < m; i++)
    {
      pCnt[p[i] - 'a']++; // pCnt 算完就固定死了
      sCnt[s[i] - 'a']++;
    }
    if (pCnt == sCnt)
      res.push_back(0);

    for (int i = m; i < n; i++)
    {
      // 减去之前开头索引字符，加上新的结尾字符
      sCnt[s[i - m] - 'a']--;
      sCnt[s[i] - 'a']++;

      // 然后再比较这一段子字符串是否相等
      if (pCnt == sCnt)
        res.push_back(i - m + 1);
    }

    return res;
  }
};

int main()
{
  string s1 = "cbaebabacd", p1 = "abc";
  vector<int> res1 = Solution438().findAnagrams(s1, p1);
  for (int i = 0; i < res1.size(); i++)
    cout << res1[i];

  return 0;
}