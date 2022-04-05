#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution762
{
private:
  // 题目的数据都是正数，不需要考虑补码算术右移操作情况
  // bitCount() 官方源码
  int hammingWeight(int n)
  {
    n = n - ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n + (n >> 4)) & 0x0f0f0f0f;
    n = n + (n >> 8);
    n = n + (n >> 16);
    return n & 0x3f;
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
      if (hash[hammingWeight(i)])
        res++;

    return res;
  }
};

int main(void)
{
  return 0;
}
