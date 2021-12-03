#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

class Solution1005
{
public:
  int largestSumAfterKNegations(vector<int> &nums, int k)
  {
    int n = nums.size();
    int negativeSumCnt = 0;
    int sum = 0, absSum = 0; // 数组和 与 绝对值元素数组和
    int minVal = INT_MAX, absMinVal = INT_MAX;
    priority_queue<int, vector<int>, greater<int>> pq; // 小顶堆

    // 读取负数情况
    for (const auto &num : nums)
    {
      if (num < 0)
        negativeSumCnt++;

      sum += num;
      absSum += abs(num);
      minVal = min(minVal, num);
      absMinVal = min(absMinVal, abs(num));
      pq.emplace(num);
    }

    int res = 0;
    // 分情况讨论，具体看笔记
    if (negativeSumCnt == 0)
    {
      // k 为偶数
      if (k % 2 == 0)
        res = sum;
      else
        res = sum - minVal * 2;
    }
    else
    {
      if (k < negativeSumCnt)
      {
        while (!pq.empty() && k-- > 0)
        {
          int tmp = pq.top();
          pq.pop();
          sum = sum + (-tmp) * 2;
        }

        res = sum;
      }
      else
      {
        int remaining = k - negativeSumCnt;
        if (remaining % 2 == 0)
          res = absSum;
        else
          res = absSum - absMinVal * 2;
      }
    }

    return res;
  }
};

int main()
{
  int k1 = 1;
  vector<int> nums1 = {4, 2, 3};
  cout << Solution1005().largestSumAfterKNegations(nums1, k1) << endl;

  int k2 = 3;
  vector<int> nums2 = {3, -1, 0, 2};
  cout << Solution1005().largestSumAfterKNegations(nums2, k2) << endl;

  int k3 = 2;
  vector<int> nums3 = {2, -3, -1, 5, -4};
  cout << Solution1005().largestSumAfterKNegations(nums3, k3) << endl;

  int k4 = 4;
  vector<int> nums4 = {6, -4, 2, 5};
  cout << Solution1005().largestSumAfterKNegations(nums4, k4) << endl;

  return 0;
}