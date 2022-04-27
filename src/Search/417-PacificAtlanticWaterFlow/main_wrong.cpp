#include <iostream>
#include <vector>

using namespace std;

class Solution417
{
private:
  int N, M;
  const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  bool inGrid(int i, int j)
  {
    return i >= 0 && i < N && j >= 0 && j < M;
  }

  bool dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, vector<vector<bool>> successPoints, int curI, int curJ)
  {
    if (!inGrid(curI, curJ))
      return false;

    if (successPoints[curI][curJ] || curI == 0 && curJ == M || curI == N && curJ == 0)
      return true;

    bool flag = false;
    // 这里的 dfs 转移条件是必须大于等于下个格子的值才能
    for (int i = 0; i < 4; i++)
    {
      int newI = curI + direction[i][0];
      int newJ = curJ + direction[i][1];
      if (inGrid(newI, newJ) && !visited[newI][newJ] && heights[curI][curJ] >= heights[newI][newJ])
      {
        visited[newI][newJ] = true;
        flag = dfs(heights, visited, successPoints, newI, newJ);
        visited[newI][newJ] = false;
      }
    }

    return flag;
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    N = heights.size();
    M = heights[0].size();
    vector<vector<int>> res;
    vector<vector<bool>> visited(N, vector<bool>(M));
    vector<vector<bool>> successPoints(N, vector<bool>(M));

    // 暴力遍历每个节点的值，dfs 查看它是否能到左下角或者右上角
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        visited[i][j] = true;
        bool isReach = dfs(heights, visited, successPoints, i, j);
        visited[i][j] = false;
        if (isReach)
        {
          res.push_back({i, j});
          successPoints[i][j] = true;
        }
      }
    }

    return res;
  }
};

int main(void)
{
  vector<vector<int>> arr1 = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
  Solution417().pacificAtlantic(arr1);

  return 0;
}
