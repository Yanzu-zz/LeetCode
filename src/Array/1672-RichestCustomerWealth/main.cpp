#include <iostream>
#include <vector>

using namespace std;

class Solution1672
{
public:
  int maximumWealth(vector<vector<int>> &accounts)
  {
    int n = accounts.size(), res = 0;

    // 暴力计算哪个最大即可
    for (int i = 0; i < n; i++)
    {
      int len = accounts[i].size(), sum = 0;
      for (int j = 0; j < len; j++)
        sum += accounts[i][j];

      res = sum > res ? sum : res;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
