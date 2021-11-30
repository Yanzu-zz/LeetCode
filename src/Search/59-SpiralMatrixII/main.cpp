#include <iostream>
#include <vector>

using namespace std;

class Solution59
{
private:
  int N;
  int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool inMatrix(int i, int j)
  {
    return i >= 0 && i < N && j >= 0 && j < N;
  }

  void dfs(vector<vector<int>> &res, int step, int stickIn, int i, int j)
  {
    // boundary condition
    if (step > N * N + 1)
      return;

    // 这里的res就可以代替visited数组了
    if (res[i][j] == 0)
      res[i][j] = step;

    int newI = i + direction[stickIn][0];
    int newJ = j + direction[stickIn][1];
    if (!inMatrix(newI, newJ) || res[newI][newJ] != 0)
    {
      stickIn = (stickIn + 1) % 4;
      newI = i + direction[stickIn][0];
      newJ = j + direction[stickIn][1];
    }

    if (inMatrix(newI, newJ) && res[newI][newJ] == 0)
      dfs(res, step + 1, stickIn, newI, newJ);
  }

public:
  vector<vector<int>> generateMatrix(int n)
  {
    N = n;
    vector<vector<int>> res(n, vector(n, 0));
    dfs(res, 1, 0, 0, 0);

    return res;
  }
};

int main()
{

  return 0;
}