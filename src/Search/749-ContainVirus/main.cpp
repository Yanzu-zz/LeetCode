#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int curWall = 0, rows = 0, cols = 0;

  void spread(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y)
  {
    // 往四个方向扩散（标记值为1）
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
      int newX = x + dirs[i][0];
      int newY = y + dirs[i][1];
      if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && visited[newX][newY] == 0)
      {
        //扩散区域
        if (grid[newX][newY] == 0)
        {
          grid[newX][newY] = 1;
          visited[newX][newY] = 1;
        }
        else if (grid[newX][newY] == 1)
        {
          spread(grid, visited, newX, newY);
        }
      }
    }
  }

  void modifyDead(vector<vector<int>> &grid, int x, int y)
  {
    grid[x][y] = -2; // 标记死亡
    for (int i = 0; i < 4; i++)
    {
      int newX = x + dirs[i][0];
      int newY = y + dirs[i][1];
      // DFS 寻找四个方向上连着的 grid 值为 1 的方格
      if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1)
        modifyDead(grid, newX, newY);
    }
  }

  int dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y, int state)
  {
    int curArea = 0;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
      int newX = x + dirs[i][0];
      int newY = y + dirs[i][1];
      if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && visited[newX][newY] != 1)
      {
        //不是病毒
        if (grid[newX][newY] == 0)
        {
          curWall++;
          // 是否已经访问，是的话只加墙，不是需要加墙和区域（一个区域有四个墙）
          if (visited[newX][newY] != state)
          {
            curArea++;
            visited[newX][newY] = state;
          }
        }
        else if (grid[newX][newY] == 1)
        {
          // 是存活病毒
          curArea += dfs(grid, visited, newX, newY, state);
        }
      }
    }

    return curArea;
  }

  int getMaxAreaNeedWalls(vector<vector<int>> &grid)
  {
    // maxArea代表最大的感染区,ans代表需要修的墙的数量,
    // targetX、targetY表示此区域的DFS开始的坐标
    // state表示当前区域要修建墙的状态,如果没有修过,需要给maxArea+1,修过的话，只加墙的数量,不加maxArea
    // 并且每个区域的state都是不一样的，互相不能影响 DFS完给state-1
    int maxArea = 0, ans = 0, targetX = -1, targetY = -1, state = -3;

    // 开始深搜寻找
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        // 找到没有访问的病毒区域
        if (grid[i][j] == 1 && visited[i][j] == 0)
        {
          // 当前区域需要的防火墙数量
          curWall = 0;
          // 当前区域能感染的数量
          int curMaxArea = dfs(grid, visited, i, j, state);
          if (curMaxArea > maxArea)
          {
            maxArea = curMaxArea;
            ans = curWall;
            targetX = i;
            targetY = j;
          }
          state--;
        }
      }
    }

    // 没东西搜了
    if (targetX == -1)
      return 0;

    // 将这次围住的病毒改为死亡状态（其实就是更改值）
    modifyDead(grid, targetX, targetY);

    // 扩散剩余病毒（四个方向，对角线不能扩散）
    visited.assign(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        if (grid[i][j] == 1 && visited[i][j] == 0)
          spread(grid, visited, i, j);
    }

    return ans;
  }

  int containVirus(vector<vector<int>> &isInfected)
  {
    this->rows = isInfected.size();
    this->cols = isInfected[0].size();

    int res = 0;
    while (true)
    {
      // 每次循环都选能感染区域数量最多的那一团病毒进行隔离
      int walls = getMaxAreaNeedWalls(isInfected);
      // 当检测不到病毒能感染时就表明任务结束了
      if (walls == 0)
        break;

      // 否则就封印当前这个最大病毒团，将需要用上的墙的数量记上
      res += walls;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
