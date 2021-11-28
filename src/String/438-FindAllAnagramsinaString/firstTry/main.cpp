#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution438
{
private:
  const static int MOD = 1610612741;
  int alphaHash(string str)
  {
    int n = str.size();
    long hashVal = 1;
    for (int i = 0; i < n; i++)
      hashVal = ((hashVal % MOD) * str[i]) % MOD;

    return (int)hashVal;
  }

public:
  vector<int> findAnagrams(string s, string p)
  {
    int n = s.size(), m = p.size();
    if (m > n)
      return {};

    vector<int> res;
    const int pHash = alphaHash(p);
    // 特判，第一个元素我们手动赋值
    int currHash = alphaHash(s.substr(0, m));
    if (currHash == pHash)
      res.push_back(0);

    // 从第二个字符开始
    for (int i = 1; i + m <= n; i++)
    {
      currHash = ((currHash % MOD) / s[i - 1]) % MOD;
      if (currHash == 0)
        currHash = 1;
      currHash = ((currHash % MOD) * s[i + m - 1]) % MOD;

      if (currHash == pHash)
        res.push_back(i);
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