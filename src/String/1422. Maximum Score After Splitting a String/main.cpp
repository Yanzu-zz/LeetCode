#include <iostream>
#include <vector>

using namespace std;

class Solution1422
{
public:
  int maxScore(string s)
  {
    int n = s.size(), zeroScore = 0, oneScore = 0;

    // 先计算分割第一个字符的得分
    zeroScore += s[0] == '0';
    for (int i = 1; i < n; i++)
      oneScore += s[i] == '1';

    int res = zeroScore + oneScore;
    // 然后模拟分割线逐渐右移的情况
    for (int i = 1; i < n - 1; i++)
    {
      zeroScore += s[i] == '0';
      oneScore -= s[i] == '1';

      res = max(res, zeroScore + oneScore);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
