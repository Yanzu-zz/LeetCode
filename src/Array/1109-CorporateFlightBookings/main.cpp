#include <iostream>
#include <vector>

using namespace std;

class Solution1109
{
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
  {
    vector<int> res(n, 0);

    // 开始作 差分数组
    for (auto &booking : bookings)
    {
      // 因为对应的是数组，所以需要 -1，而 right 是需要对 right+1 位置进行处理，故我们不需要-1
      int left = booking[0] - 1, right = booking[1], seats = booking[2];

      // 对 c[l] += c：由于差分是前缀和的逆向过程，这个操作对于将来的查询而言，带来的影响是对于所有的下标大于等于 l 的位置都增加了值 v；
      res[left] += seats;
      // 对 c[r + 1] -= v：由于我们期望只对 [l,r] 产生影响，因此需要对下标大于 r 的位置进行减值操作，从而抵消“影响”。
      if (right < n)
        res[right] -= seats;
    }

    // 接下来就是对差分数组做前缀和运算就能得出答案
    for (int i = 1; i < n; i++)
      res[i] += res[i - 1];

    return res;
  }
};

int main(void)
{

  return 0;
}
