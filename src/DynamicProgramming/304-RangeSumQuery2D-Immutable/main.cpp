#include <iostream>
#include <vector>

using namespace std;

/**
 * 解决思路：用和 303 问题一样的思路——一维前缀和（超时）
 * 只不过这里需要多行的前缀和相加再返回即可
 */
class NumMatrix
{
  vector<vector<int>> preSum;

public:
  NumMatrix(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();
    int i, j;

    preSum.resize(m, vector<int>(n + 1));
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        preSum[i][j + 1] = preSum[i][j] + matrix[i][j];
    }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    int sum = 0;
    int i, j;
    // 需要注意的是我们的 preSum 是对应 row1和2 的
    for (i = row1; i <= row2; i++)
      sum += preSum[i][col2 + 1] - preSum[i][col1];

    return sum;
  }
};

int main(void)
{
  vector<vector<int>> arr1 = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};

  NumMatrix *num1 = new NumMatrix(arr1);
  cout << num1->sumRegion(2, 1, 4, 3) << endl;
  cout << num1->sumRegion(1, 1, 2, 2) << endl;
  cout << num1->sumRegion(1, 2, 2, 4) << endl;

  return 0;
}
