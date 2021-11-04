#include <iostream>
#include <vector>

using namespace std;

class Solution367
{
public:
  bool isPerfectSquare(int num)
  {
    int left = 1, right = num / 2 + 1;
    // 开始二分
    // 因为我们在移动左侧边界 left 和右侧边界 right 时，新的搜索区间都不会包含被检查的下标 mid，所以搜索区间的边界始终是我们没有检查过的。因此，当 left = right时，我们仍需要检查 mid = (left + right) / 2。
    while (left <= right)
    {
      // 算中值的平方
      int mid = left + (right - left >> 1);
      long square = (long)mid * mid;

      // 下面就是小了则右移，大了就左移，等于就返回true
      if (square == num)
        return true;
      else if (square > num)
        right = mid - 1;
      else
        left = mid + 1;
    }

    return false;
  }
};

int main()
{

  return 0;
}