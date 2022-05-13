#include <iostream>
#include <vector>

using namespace std;

class Solution0105
{
public:
  bool oneEditAway(string first, string second)
  {
    // 观察题目，不难得出，满足题意的字符串必定只有两个以下的位置不同，那么我们可以正向遍历与反向遍历一次，分别取得两者的首个不同的位置，再根据该位置与字符串末尾的距离差值进行判断。
    auto pos1 = mismatch(first.cbegin(), first.cend(), second.cbegin(), second.cend());
    auto pos2 = mismatch(first.crbegin(), first.crend(), second.crbegin(), second.crend());

    ptrdiff_t dis[4]{first.cend() - pos1.first, second.cend() - pos1.second, pos2.first - first.crbegin(), pos2.second - second.crbegin()};
    return ((int)dis[0] - dis[2] < 2) && ((int)dis[1] - dis[3] < 2);
  }
};

int main(void)
{

  return 0;
}
