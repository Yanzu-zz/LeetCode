#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 中心扩散法计算最长回文子串
/**
 * 1. 往左扩散，如果左边和当前值相等，则left--，仍然还是left= right=3，len=1
 * 2. 往右扩散，如果右边和当前值相等，则right++，变为left=3，right=4，len=2
 * 3. 左右右扩散，如果右边和左边相等，则rght++，left--，变为lft=2，right=5，len=4
 */
class Solution05
{
public:
  string longestPalindrome(string s)
  {
    if (s.length < 2)
      return s;

    int strLen = s.length;
    int maxStart = 0; //最长回文串的起点
    int maxEnd = 0;   //最长回文串的终点
    int maxLen = 1;   //最长回文串的长度

    vector<vector<bool>> dp(strLen, vector<bool>(strLen, false));
  }
};

int main(void)
{

  return 0;
}
