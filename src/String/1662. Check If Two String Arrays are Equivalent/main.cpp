#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
  {
    int n = word1.size(), m = word2.size();
    int p1 = 0, p2 = 0, i = 0, j = 0;

    while (p1 < n && p2 < m)
    {
      // 剪枝
      if (word1[p1][i] != word2[p2][j])
        return false;

      // 到达一个子数组边界，则到下个数组中
      if (++i == word1[p1].size())
      {
        i = 0;
        p1++;
      }

      if (++j == word2[p2].size())
      {
        j = 0;
        p2++;
      }
    }

    return p1 == n && p2 == m;
  }
};

int main(void)
{

  return 0;
}
