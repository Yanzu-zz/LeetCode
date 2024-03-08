class Solution:
  def minimumPossibleSum(self, n: int, target: int) -> int:
    t = target // 2
    ans = 0

    if n <= t:
      ans = (n * (n + 1) // 2) % 1_000_000_007
    elif n > t:
      # ans = ((t * (t + 1) // 2) + ((n - t - 1 + 2 * target) * (n - t) // 2)) % 1_000_000_007
      ans = (t*(t+1)//2 + (n-t)*target + (n-t)*(n-t-1)//2) % 1_000_000_007

    return ans
