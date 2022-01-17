#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

using LL = long long;
using Mat = vector<vector<LL>>;

class Solution1220_2
{
public:
  Mat multiply(const Mat &matrixA, const Mat &matrixB, LL mod)
  {
    int m = matrixA.size();
    int n = matrixB[0].size();
    Mat res(m, vector<LL>(n, 0));
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        for (int k = 0; k < matrixA[i].size(); ++k)
        {
          res[i][j] = (res[i][j] + matrixA[i][k] * matrixB[k][j]) % mod;
        }
      }
    }
    return res;
  }

  Mat fastPow(const Mat &matrix, LL n, LL mod)
  {
    int m = matrix.size();
    Mat res(m, vector<LL>(m, 0));
    Mat curr = matrix;

    for (int i = 0; i < m; ++i)
    {
      res[i][i] = 1;
    }
    for (int i = n; i != 0; i >>= 1)
    {
      if (i & 1)
      {
        res = multiply(curr, res, mod);
      }
      curr = multiply(curr, curr, mod);
    }
    return res;
  }

  int countVowelPermutation(int n)
  {
    LL mod = 1e9 + 7;
    Mat factor =
        {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0}};
    Mat res = fastPow(factor, n - 1, mod);
    long long ans = 0;
    for (int i = 0; i < 5; ++i)
    {
      ans = (ans + accumulate(res[i].begin(), res[i].end(), 0LL)) % mod;
    }
    return ans;
  }
};

int main(void)
{

  return 0;
}
