#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<string> letterCasePermutation(string s)
  {
    vector<string> res;
    int n = s.size();
    dfs(s, n, 0, res);

    return res;
  }

  void dfs(string s, int n, int pos, vector<string> &res)
  {
    while (pos < n && s[pos] >= '0' && s[pos] <= '9')
      pos++;

    if (pos == n)
    {
      res.emplace_back(s);
      return;
    }

    // 先用小写（大写）形式爆搜后面的字符串
    s[pos] ^= 32;
    dfs(s, n, pos + 1, res);
    // 再用大写（小写）形式爆搜
    s[pos] ^= 32;
    dfs(s, n, pos + 1, res);
  }
};

int main(void)
{

  return 0;
}
