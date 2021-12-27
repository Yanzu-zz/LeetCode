#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution825
{
public:
  int numFriendRequests(vector<int> &ages)
  {
    int n = ages.size();
    sort(ages.begin(), ages.end());

    int res = 0;
    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
      if (ages[i] < 15)
        continue;

      int lLimit = 0.5 * ages[i] + 7;
      // 如果左指针指向的元素小于 limit 了，则表明当前元素不能被发送 friend request 了，需要往右边走了
      while (ages[left] <= lLimit)
        left++;

      // 右指针就是看右边是否比当前元素小了，小了就更新最新的位置
      while (right + 1 < n && ages[right + 1] <= ages[i])
        right++;

      res += right - left;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
