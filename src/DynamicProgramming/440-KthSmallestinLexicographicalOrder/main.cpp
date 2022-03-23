#include <iostream>
#include <vector>

using namespace std;

class Solution440
{
private:
  // 确定指定前缀下所有子节点数，如 [10,13] 有 4 个 -> 10,11,12,13
  // [1, 13] 有 5 个 -> 1,10,11,12,13
  // 注意用 int 会溢出
  long findCount(long prefix, long n)
  {
    long res = 0;
    for (long cur = prefix, next = prefix + 1; cur <= n; cur *= 10, next *= 10)
      res += min(next, n + 1) - cur;

    return res;
  }

public:
  int findKthNumber(int n, int k)
  {
    // 我们从 1 开始计算
    long prefix = 1;

    // 利用 k 次放大或平移子区间找到第 k 大元素
    long i = 1; // 指明当前是第几大元素
    while (i < k)
    {
      long count = findCount(prefix, n); // 获得当前前缀下所有子节点的和
      if (i + count > k)                // 如果当前找的第 k 大元素在当前前缀下，我们放大它
      {
        prefix *= 10; // prefix 进入它的子字典树
        i++;
      }
      else // 如果当前找的第 k 大元素不在当前前缀下，我们平移它到下一前缀节点上
      {
        prefix++;   // 往右边平移
        i += count; // 相应的平移了当前节点，那么当前节点的总数需要加上去
      }
    }

    // 最后找到的就是我们要的结果
    return prefix;
  }
};

int main(void)
{

  return 0;
}
