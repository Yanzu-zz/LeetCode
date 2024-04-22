class Solution:
  def combinationSum4(self, nums: List[int], target: int) -> int:
    @cache
    def dfs(t):
      if t == 0:
        return 1

      return sum(dfs(t - x) for x in nums if x <= t)
    return dfs(target)
