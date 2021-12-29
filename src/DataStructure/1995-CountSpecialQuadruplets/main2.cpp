#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1995
{
public:
  int countQuadruplets(vector<int> &nums)
  {
    int res = 0;
    int n = nums.size();
    unordered_map<int, int> mp;

    // 从 b 开始枚举，因为确定 b 就能确定 c
    // 注意，因为题目要求索引的大小是 a<b<c<d，故我们从 最大能取到的 b 值 n-3 开始
    for (int b = n - 3; b >= 1; b--)
    {
      int c = b + 1;

      // 接着枚举 d 计算 nums[d] - nums[c] 的差值并存入哈希表中
      for (int d = c + 1; d < n; d++)
        mp[nums[d] - nums[c]]++;

      // 有了差值之后就能计算本次确定的 abcd 的四元组数量
      // 之前轮次存储的差值能获取到也能算入返回值，因为数字很可能会重复
      for (int a = 0; a < b; a++)
        res += mp[nums[a] + nums[b]];
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
