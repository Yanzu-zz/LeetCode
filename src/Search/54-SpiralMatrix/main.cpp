#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution54
{
private:
  int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int n, m;
  int totalCnt;

  bool inMatrix(int x, int y)
  {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  void dfs(vector<vector<int>> &matrix, vector<int> &res, vector<vector<bool>> &visited, int step, int x, int y, int stackOn)
  {
    // 边界条件
    if (step >= totalCnt)
      return;

    // 当前这个点时第一次访问，那么就加入返回数组
    if (!visited[x][y])
    {
      visited[x][y] = true;
      res.push_back(matrix[x][y]);
    }

    // 计算下一个该走的点位
    int newX = x + direction[stackOn][0];
    int newY = y + direction[stackOn][1];
    // 如果下个该走的点位越界了或者已经走过了，则变换该走的方向
    if (!inMatrix(newX, newY) || visited[newX][newY])
    {
      stackOn = (stackOn + 1) % 4;
      newX = x + direction[stackOn][0];
      newY = y + direction[stackOn][1];
    }

    // 开始 dfs
    if (inMatrix(newX, newY) && !visited[newX][newY])
      dfs(matrix, res, visited, step + 1, newX, newY, stackOn);
  }

public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    // 初始化工作
    n = matrix.size(), m = matrix[0].size();
    totalCnt = n * m;
    if (n == 1)
      return matrix[0];

    vector<int> res;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    dfs(matrix, res, visited, 0, 0, 0, 0);

    return res;
  }
};

int main()
{
  vector<vector<int>> matrix1 = {{3}, {2}};
  vector<int> res1 = Solution54().spiralOrder(matrix1);
  for (int i = 0; i < res1.size(); i++)
    cout << res1[i];
  cout << endl;

  return 0;
}