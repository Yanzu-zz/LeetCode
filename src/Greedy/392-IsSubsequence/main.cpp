#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution392
{
public:
  bool isSubsequence(string s, string t)
  {
    int sLen = s.size(), tLen = t.size();
    if (tLen < sLen)
      return false;
    if (sLen == tLen)
      return s.compare(t) == 0;

    int si = 0, ti = 0;
    while (ti < tLen && si < sLen)
    {
      if (t[ti] == s[si])
      {
        ti++;
        si++;
      }
      else
        ti++;
    }

    if (si != sLen)
      return false;
    else
      return true;
  }
};

int main(void)
{
  string s1 = "abc", t1 = "ahbgdc";
  string s2 = "abx", t2 = "ahbgdc";

  cout << Solution392().isSubsequence(s1, t1) << endl;
  cout << Solution392().isSubsequence(s2, t2) << endl;

  return 0;
}
