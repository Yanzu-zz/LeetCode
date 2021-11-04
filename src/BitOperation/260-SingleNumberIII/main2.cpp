#include <iostream>
#include <vector>

using namespace std;

class Solution260_2
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    int n = nums.size();
    int xorSum = 0;
    for (int num : nums) // 异或整个数组，这样xorsum就为 所求数字1^所求数字2
      xorSum ^= num;

    // 使用位运算 x & -x 取出 x 的二进制表示中最低位那个 1
    int lsb = (xorSum == INT_MIN ? xorSum : xorSum & (-xorSum)); // Least Significant Bit
    int res1 = 0, res2 = 0;
    for (const auto &num : nums)
    {
      if (num & lsb)
        res1 ^= num;
      else
        res2 ^= num;
    }

    return {res1, res2};
  }
};

int main()
{

  return 0;
}