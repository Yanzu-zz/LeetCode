#include <iostream>
#include <vector>

using namespace std;

class Solution821
{
public:
  vector<int> shortestToChar(string s, char c)
  {
    int n = s.size();
    vector<int> res(n, 0);

    // 开始遍历查看最近距离
    int idx = -n;
    for (int i = 0; i < n; i++)
    {
      // 记录最新遇到的 c 的索引位置
      if (s[i] == c)
        idx = i;

      // 然后更新它
      // 如果一开始还没遇到过则置大于等于 n 距离的值
      res[i] = i - idx;
    }

    // 接着从右边往左边再更新一次
    idx = 2 * n;
    for (int i = n - 1; i >= 0; i--)
    {
      // 老样子，还是记录最新索引
      if (s[i] == c)
        idx = i;

      // 接着就是更新最小值（可以的话）
      // 因为先前有过一次记录，故需要与之对比哪个更小
      res[i] = min(res[i], idx - i);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
