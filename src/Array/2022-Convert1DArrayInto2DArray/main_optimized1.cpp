#include <iostream>
#include <vector>

using namespace std;

class Solution2022_optimized
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    vector<vector<int>> res(m,vector<int>(n));
    if (m * n != original.size())
      return vector<vector<int>>();

    for (int i = 0, idx = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        res[i][j] = original[idx++];

    return res;
  }
};

int main(void)
{

  return 0;
}
