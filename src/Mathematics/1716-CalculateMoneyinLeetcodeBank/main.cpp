#include <iostream>
#include <vector>

using namespace std;

class Solution1716
{
public:
  int totalMoney(int n)
  {
    int weeks = n / 7;
    int days = n % 7;
    int res = 0;

    // 使用等差数列求前 n 项和公式快速算周的钱数
    int a1 = 28, d = 7;
    res += (weeks * a1) + (weeks * (weeks - 1) * d / 2);
    // 天的钱数
    while (days-- > 0)
      res += (++weeks);

    return res;
  }
};

int main(void)
{
  int n1 = 4;
  cout << Solution1716().totalMoney(n1) << endl;

  int n2 = 10;
  cout << Solution1716().totalMoney(n2) << endl;

  int n3 = 20;
  cout << Solution1716().totalMoney(n3) << endl;

  return 0;
}