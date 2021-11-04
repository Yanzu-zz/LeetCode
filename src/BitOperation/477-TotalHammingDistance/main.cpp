#include <iostream>
#include <vector>

using namespace std;

/**
 * 暴力法（超时）
 */
class Solution477
{
public:
  int totalHammingDistance(vector<int> &nums)
  {
    int n = nums.size();
    int i, j, ret = 0;

    for (i = 0; i < n; i++)
      for (j = i + 1; j < n; j++)
        // 异或之后，不同的位置是得 1，然后根据系统提供的函数计算有多少位 1 就知道结果了
        ret += __builtin_popcount(nums[i] ^ nums[j]);

    return ret;
  }
};

int main(void)
{
  vector<int> arr1 = {4, 14, 2};

  cout << Solution477().totalHammingDistance(arr1) << endl;

  return 0;
}
