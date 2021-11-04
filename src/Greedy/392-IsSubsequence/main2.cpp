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
      
    int si = 0;
    for (int i = 0; i < tLen && si < sLen; i++)
      if (t[i] == s[si])
        si++;

    return si == sLen;
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
