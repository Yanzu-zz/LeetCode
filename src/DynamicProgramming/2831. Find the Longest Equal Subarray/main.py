from collections import Counter


class Solution:
  def longestEqualSubarray(self, nums: List[int], k: int) -> int:
    ans = 0
    n = len(nums)
    # dp = [0] * (n+1)
    dp = Counter()
    maxV = -1

    for n in nums:
      dp[n] += 1
      ans = max(ans, dp[n])
      maxV = max(maxV, n)

    return ans if k > 0 else maxV
