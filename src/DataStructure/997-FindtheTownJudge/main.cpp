#include <iostream>
#include <vector>

using namespace std;

class Solution997
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    vector<int> inDegrees(n + 1);
    vector<int> outDegrees(n + 1);

    for (auto &edge : trust)
    {
      // x 为出度，y 为入度
      int x = edge[0], y = edge[1];
      inDegrees[y]++;
      outDegrees[x]++;
    }

    // 然后判断是否一个人的入度 为 n-1，出度为 0，那么这个人就是我们要找的法官
    for (int i = 1; i <= n; i++)
      if (inDegrees[i] == n - 1 && outDegrees[i] == 0)
        return i;

    return -1;
  }
};

int main(void)
{

  return 0;
}
