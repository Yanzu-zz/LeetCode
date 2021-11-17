#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    int n = strs.size();
    if (n == 1)
      return strs[0];

    string res = "";

    // 纵向扫描
    for (int j = 0; j < strs[0].size(); j++)
    {
      int i;
      for (i = 1; i < n && strs[i][j] == strs[i - 1][j]; i++)
        ;

      // 如果不能到达最后一个，则表明当前所有字符串的后面的字符都不是公共得了
      if (i != n)
        break;

      // 否则当前位置开始还是公共的
      res += strs[0][j];
    }

    return res;
  }
};

int main()
{

  return 0;
}