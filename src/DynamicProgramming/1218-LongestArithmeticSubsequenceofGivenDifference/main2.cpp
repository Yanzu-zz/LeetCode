#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1218
{
public:
  int longestSubsequence(vector<int> &arr, int difference)
  {
    int n = arr.size();
    // 利用哈希表的快速索引特性加速查找
    unordered_map<int, int> dp;
    int res = 0;
    for (int num : arr)
    {
      dp[num] = dp[num - difference] + 1;
      res = max(res, dp[num]);
    }

    return res;
  }
};

int main()
{

  return 0;
}