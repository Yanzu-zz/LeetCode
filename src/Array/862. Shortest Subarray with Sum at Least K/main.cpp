#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
  int shortestSubarray(vector<int> &nums, int k)
  {
    int n = nums.size(), res = n + 1;
    vector<long> preSum(n + 1); // 前缀和数组
    preSum[0] = 0L;

    // 计算前缀和
    for (int i = 0; i < n; i++)
      preSum[i + 1] = nums[i] + preSum[i];

    // 然后就是利用前缀和来计算结果了
    deque<int> q;
    for (int i = 0; i <= n; i++)
    {
      long curr = preSum[i];
      // 如果当前 长度 的子数前缀和超过了 k
      while (!q.empty() && curr - preSum[q.front()] >= k)
      {
        res = min(res, i - q.front());
        q.pop_front();
      }

      // 如果当前后面的前缀和大小超过了当前的前缀和，那么当前的长度肯定比它短
      while (!q.empty() && preSum[q.back()] >= curr)
        q.pop_back();

      q.push_back(i);
    }

    return res > n ? -1 : res;
  }
};

int main(void)
{

  return 0;
}
