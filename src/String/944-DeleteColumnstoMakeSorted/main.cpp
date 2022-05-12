#include <iostream>
#include <vector>

using namespace std;

class Solution944
{
public:
  int minDeletionSize(vector<string> &strs)
  {
    int n = strs.size(), m = strs[0].size();

    int res = 0;
    for (int j = 0; j < m; j++)
      for (int i = 1; i < n; i++)
        if (strs[i - 1][j] > strs[i][j]) // 记录一行，可能会删除很多行，所以需要继续循环
        {
          res++;
          break;
        }

    return res;
  }
};

int main(void)
{

  return 0;
}
