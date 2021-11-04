#include <iostream>
#include <vector>

using namespace std;

/**
 * 二维前缀和
 */
class NumMatrix
{
  vector<vector<int>> preSum;

public:
  NumMatrix(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();
    int i, j;

    preSum.resize(m + 1, vector<int>(n + 1));
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        // 根据递推公式写出方程即可
        preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + matrix[i][j];
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
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
