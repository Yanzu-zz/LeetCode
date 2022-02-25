#include <iostream>
#include <vector>

using namespace std;

class Solution400
{
public:
  int findNthDigit(int n)
  {
    int N = n;
    int digits = 1;       // 位数
    long long border = 9; // digits 位数一共产生多少位数字存储变量

    // 宏观调整
    // 也可以用 math.pow 做
    while (N)
    {
      long long tmp = border * digits;
      if (N <= tmp)
        break;

      N -= tmp; // 每次循环扣除 当前digits 位数的数的总数字个数（如 2位数就为 10-99 一共180个）

      digits++; // 对下一个位数进行处理（比如 从2位数10-99 处理 100-999三位数的数的个数）
      border *= 10;
    }

    // 微观调整
    // 循环结束后 剩余的N都是由 digits位数 贡献的
    // 每个 digits位数 都产生了 digits个数字； 因而我们求除求余就可以知道n对应的是第几个digits位数

    int offset = (N - 1) / digits;
    int begin = 1;
    for (int i = 0; i < digits - 1; i++)
      begin *= 10;

    int mod = (N - 1) % digits;
    string target = to_string(offset + begin);
    int ans = target[mod] - '0';

    return ans;
  }
};

int main()
{

  return 0;
}