#include <iostream>
#include <vector>

using namespace std;

class Solution2022_optimized
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    vector<vector<int>> res;
    if (m * n != original.size())
      return res;

    // 一次添加一行
    for (auto it = original.begin(); it != original.end(); it += n)
      res.emplace_back(it, it + n);

    return res;
  }
};

int main(void)
{

  return 0;
}
