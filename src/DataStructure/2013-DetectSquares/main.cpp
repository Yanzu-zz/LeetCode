#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class DetectSquares
{
private:
  unordered_map<int, unordered_map<int, int>> mp;

public:
  DetectSquares()
  {
  }

  void add(vector<int> point)
  {
    mp[point[0]][point[1]]++;
  }

  int count(vector<int> point)
  {
    int x0 = point[0];
    int y0 = point[1];
    int res = 0;

    // 遍历与 横坐标x0 在同一条线上的坐标
    for (auto yc : mp[x0])
    {
      int y1 = yc.first;
      // 不能是自己
      if (y1 == y0)
        continue;

      // 算出边长
      // 注意，如果算出了以下面为基准的边长，我们就要用这个边长去找剩下的符合边长长度的3个点
      int edge = abs(y1 - y0);
      // yc.second 是表示当前这个点位有多少个重复的点（题目规定可以重复添加）
      // 而后面的括号内就表示 以当前点位基准能有多少个正方形
      res += yc.second * (mp[x0 + edge][y1] * mp[x0 + edge][y0] + mp[x0 - edge][y1] * mp[x0 - edge][y0]);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
