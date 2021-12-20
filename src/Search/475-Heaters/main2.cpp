#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findRadius(vector<int> &houses, vector<int> &heaters)
  {
    // 对两个数组都进行排序
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    // 给暖气片位置加上头尾，这样好算一些
    heaters.insert(heaters.begin(), INT_MIN);
    heaters.emplace_back(INT_MAX);

    int cur = 0;
    int n = houses.size(), m = heaters.size();
    long long res = INT_MIN;
    // 然后进行指针移动计算
    for (int i = 0; i < n; i++)
    {
      // 指针移动的目的是找到最近的供暖器位置
      while (cur < m + 2)
      {
        // 如果当前位置比房子远，则证明找到了这个第一个超过房子距离的暖气片
        if (heaters[cur] >= houses[i])
          break;
        cur++; // 否则就没找到，继续往下走
      }

      // 而找到之后就是对比 超过距离的暖气片 和 上一个还在房子距离内的暖气片 两者最近的的距离
      // 核心思想还是：对于每个房屋，要么用前面的暖气，要么用后面的，二者取近的，得到距离
      res = max(res, min((long long)heaters[cur] - houses[i], (long long)houses[i] - heaters[cur - 1]));
    }

    return res;
  }
};

int main()
{

  return 0;
}
