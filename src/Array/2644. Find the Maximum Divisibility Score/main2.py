class Solution:
  def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
    # 可以剪枝，思想就是当前 n < d 时候是不可能整除的
    nums.sort(reverse=True)
    maxCnt, ans = -1, divisors[0]

    for d in divisors:
      cnt = 0
      for n in nums:
        if n < d:
          break

        if n % d == 0:
          cnt += 1

      if cnt > maxCnt or (cnt == maxCnt and d < ans):
        maxCnt, ans = cnt, d

    return ans
