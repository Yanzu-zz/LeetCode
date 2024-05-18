class Solution:
  def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
    maxCnt = 0
    ans = divisors[0]
    for d in divisors:
      cnt = sum(1 for n in nums if n % d == 0)

      if cnt > maxCnt or (cnt == maxCnt and d < ans):
        ans = d
        maxCnt = cnt

    return ans
