#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution1672
{
public:
  int maximumWealth(vector<vector<int>> &accounts)
  {
    int res = INT_MIN;

    // 用 std 计算
    for (auto &account : accounts)
      res = max(res, accumulate(account.begin(), account.end(), 0));

    return res;
  }
};

int main(void)
{

  return 0;
}
