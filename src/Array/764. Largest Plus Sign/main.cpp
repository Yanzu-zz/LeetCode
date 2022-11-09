#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
  {
    if (n * n == mines.size())
      return 0;

    vector<vector<bool>> map(n, vector<bool>(n, true));
    // 标记 0
    for (auto &mine : mines)
      map[mine[0]][mine[1]] = false;

    if (n % 2 == 0)
      n--;
    while (n > 0)
    {
      int mid = n / 2;
      bool isNoneZero = true;
      for (int i = 0; i < n; i++)
      {
        if (!map[mid][i] || !map[i][mid])
        {
          isNoneZero = false;
          break;
        }
      }

      if (isNoneZero == true)
        return n - 1;

      n--;
    }

    return mines.size() != n;
  }
};

int main(void)
{

  return 0;
}
