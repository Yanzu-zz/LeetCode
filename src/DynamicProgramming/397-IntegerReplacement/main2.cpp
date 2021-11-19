#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution397
{
public:
  // 记忆化搜索一下
  unordered_map<int, int> mp;
  int integerReplacement(int n)
  {
    if (n == 1)
      return 0;

    if (mp[n] != 0)
      return mp[n];

    int result = 0;
    if (n % 2 == 0)
      result = 1 + integerReplacement(n / 2);
    else
      // 这里 2+ 的原因是，我们 min 后面直接就是跳到将当前数字转成偶数后再进行求解的操作
      // 因此这里的 2 实际上就是 1 + 把奇数变成小偶数的1次
      result = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));

    mp[n] = result;
    return result;
  }
};

int main()
{

  return 0;
}