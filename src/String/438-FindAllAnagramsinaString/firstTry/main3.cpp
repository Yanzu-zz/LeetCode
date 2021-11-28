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
    int left = 0, right = 0;
    vector<int> pCnt(26, 0);
    vector<int> sCnt(26, 0);
    for (int i = 0; i < m; i++)
      pCnt[p[i] - 'a']++; // pCnt 算完就固定死了

    for (; right < n; right++)
    {
      int currRightVal = s[right] - 'a';
      sCnt[currRightVal]++;
      // 这表明当前s子串中出现了不该出现的或者出现多了某个字符，我们舍弃掉这一段
      while (sCnt[currRightVal] > pCnt[currRightVal]) // 当 left==right 时会自动停下
      {
        int currLeftVal = s[left] - 'a';
        sCnt[currLeftVal]--;
        left++;
      }

      // 如果 right和left 之间的长度等于 m，则表明这一段子串一定是异位串
      if (right - left + 1 == m)
        res.push_back(left);
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