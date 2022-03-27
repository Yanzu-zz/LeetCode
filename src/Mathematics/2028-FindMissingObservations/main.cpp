#include <iostream>
#include <vector>

using namespace std;

class Solution2028
{
public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n)
  {
    int m = rolls.size();
    int sum = (n + m) * mean; // 总样本的和
    int missingSum = sum;     // 缺失样本的和，下面会减去对应的已知样本的和

    for (int &roll : rolls)
      missingSum -= roll;

    // 不可能有解情况
    if (missingSum < n || missingSum > 6 * n)
      return {};

    // 下面就是寻找一组合法的解了（题目只需要任意一组）
    int quotient = missingSum / n, remainer = missingSum % n;
    vector<int> res(n, 0);

    // 方法就是整除商后，余数分摊到余数个数字上，每个数加1就行
    // 即若能整除，全部遗失样本都用这个数组就行
    // 若不能整除，将对应的 remainer 个 1 分散到对应的数字中去即可
    for (int i = 0; i < n; i++)
      res[i] = quotient + (i < remainer ? 1 : 0);

    return res;
  }
};

int main(void)
{

  return 0;
}
