#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Solution
{
private:
  int total = 0;
  vector<int> preSum;
  vector<vector<int>> rects;
  mt19937 gen{random_device{}()};

public:
  Solution(vector<vector<int>> &rects)
  {
    this->rects = rects;
    // 计算前缀和
    int len = rects.size();
    this->preSum.resize(len);
    for (int i = 0; i < len; i++)
    {
      total += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
      preSum[i] = total;
    }
  }

  vector<int> pick()
  {
    // 随机生成一个目标点
    uniform_int_distribution<int> dis(0, total - 1);
    int target = dis(gen);

    // 二分查找定位矩形
    int l = 0, r = this->rects.size() - 1;
    while (l != r)
    {
      int mid = l + (r - l >> 1);
      if (target >= preSum[mid])
        l = mid + 1;
      else
        r = mid;
    }

    // 确认好在哪个矩形内部后生成点坐标
    vector<int> tmp = this->rects[l];
    int x = tmp[2] - tmp[0] + 1, y = tmp[3] - tmp[1] + 1;
    // 当前矩形开始的编号 target - base 表示当前点(target)在当前矩阵处于多少编号
    int base = preSum[l] - x * y;

    return {tmp[0] + (target - base) % x, tmp[1] + (target - base) / x};
  }
};

int main()
{

  return 0;
}