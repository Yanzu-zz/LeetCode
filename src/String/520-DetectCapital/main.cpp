#include <iostream>
#include <vector>

using namespace std;

class Solution520
{
public:
  bool detectCapitalUse(string word)
  {
    int n = word.size(), upCnt = 0;
    char firstCh = word[0];

    // 统计除首字母外的大写字符个数
    for (int i = 1; i < n; i++)
      if (word[i] - 'Z' <= 0)
        upCnt++;

    // 下面就是true的情形
    if (upCnt == 0)
      return true;
    if (firstCh >= 'A' && firstCh <= 'Z' && upCnt == n - 1)
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