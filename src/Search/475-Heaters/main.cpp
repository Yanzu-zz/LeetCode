#include <iostream>
#include <vector>

using namespace std;

class Solution475
{
public:
  int findRadius(vector<int> &houses, vector<int> &heaters)
  {
    int n = houses.size(), m = heaters.size();
    int res = INT_MIN, currDistance = INT_MAX;

    // 先对暖气位置排序
    sort(heaters.begin(), heaters.end());

    // 然后就开始遍历全部房屋，求得每个房屋离暖气片最近的距离
    // 接着题目所求的距离就是这所有最近的距离中的最大的那个
    for (int i = 0; i < n; i++)
    {
      // 对于每个房屋，要么用前面的暖气，要么用后面的，二者取近的，得到距离
      // 如果当前房子位置比第一个暖气片位置还近，那么不用算二分了，直接算他们两之间的距离即可
      if (houses[i] <= heaters[0])
      {
        currDistance = heaters[0] - houses[i];
      }
      // 这里就是当前房子的距离比最后一个暖气片位置还远，那么也不用算二分了，直接简单计算即可
      else if (houses[i] >= heaters[m - 1])
      {
        currDistance = houses[i] - heaters[m - 1];
      }
      // 否则就是在中间位置，这里我们无法直接确定，需要用二分来找到最近的距离
      else
      {
        int l = 0, r = m - 1;
        while (l < r)
        {
          int mid = l + (r - l >> 1);
          if (heaters[mid] < houses[i])
            l = mid + 1;
          else
            r = mid;
        }

        currDistance = min(heaters[l] - houses[i], houses[i] - heaters[l - 1]);
      }

      res = max(res, currDistance); // 选取这么多个房屋距离暖气片最大的那个
    }

    return res;
  }
};

int main()
{

  return 0;
}
