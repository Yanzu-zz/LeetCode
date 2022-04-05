#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution762
{
private:
  // lowbit 函数快速计算当前 x 的二进制表示中从左往右数最后一个 1 的位置，并返回其十进制表示 2^k
  // 忘了看笔记 307 题
  int lowbit(int x)
  {
    return x & (-x);
  }

public:
  int countPrimeSetBits(int left, int right)
  {
    int res = 0;
    // 初始化快速判断素数数组，int 长度为 32 位，故最大的素数为 31
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    vector<bool> hash(40, false);
    for (int prime : primes)
      hash[prime] = true;

    // 暴力枚举
    for (int i = left; i <= right; i++)
    {
      int j = i, cnt = 0;
      // 巧用 lowbit 函数计算当前 i 有多少个二进制 1
      // 而 j -= lowbit(j) 可以消除掉当前最后一个二进制 1，从而下次 lowbit(j) 就计算第二个 1 的位置，直到 j==0
      for (; j > 0; j -= lowbit(j))
        cnt++;

      if (hash[cnt])
        res++;
    }

    return res;
  }
};

int main(void)
{
  return 0;
}
