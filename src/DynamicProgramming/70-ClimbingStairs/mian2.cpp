#include <iostream>
#include <vector>

using namespace std;

/**
 * 解题思路：f(n) = f(n-1) + f(n-2)
 * 与 mian.cpp 不同的是，我们这里意识到这个题目不需要额外开 O(n) 的空间来存储结果
 * 我们只需要用3个变量来模拟滚动数组即可（状态定义需要 3 个数值）
 */
class Solution70
{
public:
  int climbStairs(int n)
  {
    // a 表示 f(n-2)；b 为 f(n-1)；
    // c 为 f(n)，初始化为走了第一格时的状况
    int a = 0, b = 0, c = 1;
    for (int i = 1; i <= n; i++)
    {
      a = b;
      b = c;
      c = a + b;
    }

    return c;
  }
};

int main(void)
{
  int n1 = 3;
  int n2 = 5;

  cout << Solution70().climbStairs(n1) << endl;
  cout << Solution70().climbStairs(n2) << endl;

  return 0;
}
