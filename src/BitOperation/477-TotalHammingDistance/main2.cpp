#include <iostream>
#include <vector>

using namespace std;

/**
 * 逐位统计
    在计算汉明距离时，我们考虑的是同一比特位上的值是否不同，而不同比特位之间是互不影响的。
    对于数组nums中的某个元素val，
    若其二进制的第i位为1，我们只需统计 nums中有多少元素的第i位为0，即计算出了val与其他元素在第i位上的汉明距离之和。
    
    具体地，若长度为n的数组nums的所有元素二进制的第i位共有c个1，n-c个0，
    则些元素在二进制的第i位上的汉明距离之和为 c·（n-c）
    我们可以从二进制的最低位到最高位，逐位统计汉明距离。
    将每一位上得到的汉明距离累加即为答案。
    具体实现时，对于整数val二进制的第i位，我们可以用代码（val>>i）&1来取出其第i位的值。
    此外，由于109~230，我们可以直接从二进制的第0位枚举到第29位。
 */
class Solution477
{
public:
  int totalHammingDistance(vector<int> &nums)
  {
    int n = nums.size();
    int i, t, ret = 0;

    for (i = 0; i < 30; i++)
    {
      t = 0;
      for (auto &num : nums)
        t += (num >> i) & 1; // 查看第 i 位上，全部数字有多少个 1

      // 得到有多少个 1 之后，就是排列组合问题了
      // 如 n = 8、t=3，则有 5个0，且分别每个0都能有匹配到 3个1
      // 即产生了 3个 不同数字的二进制数对应位不同的数量
      ret += t * (n - t);
    }

    return ret;
  }
};

int main(void)
{
  vector<int> arr1 = {4, 14, 2};

  cout << Solution477().totalHammingDistance(arr1) << endl;

  return 0;
}
