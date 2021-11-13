#include <iostream>
#include <vector>

using namespace std;

class Solution520
{
public:
  bool detectCapitalUse(string word)
  {
    int n = word.size(), upCnt = 0;

    for (const auto &ch : word)
      if (ch - 'Z' <= 0)
        upCnt++;

    if (upCnt == n || upCnt == 0)
      return true;
    if (word[0] >= 'A' && word[0] <= 'Z' && upCnt == 1)
      return true;

    return false;
  }
};

int main()
{
  string s1 = "USA";
  cout << Solution520().detectCapitalUse(s1) << endl;

  string s2 = "leetcode";
  cout << Solution520().detectCapitalUse(s2) << endl;

  string s3 = "Google";
  cout << Solution520().detectCapitalUse(s3) << endl;

  string s4 = "FLag";
  cout << Solution520().detectCapitalUse(s4) << endl;

  return 0;
}