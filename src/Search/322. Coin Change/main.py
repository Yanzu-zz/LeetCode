from math import inf


class Solution:
  def coinChange(self, coins: List[int], amount: int) -> int:
    @cache
    def dfs(i, remain):
      if i < 0:
        return 0 if remain == 0 else inf

      # 当前硬币亮比剩余的大
      if remain < coins[i]:
        return dfs(i-1, remain)

      # 看看，用当前硬币 和 不用当前硬币，试一试后一个硬币谁能用的更少
      return min(dfs(i-1, remain), dfs(i, remain - coins[i]))

    ans = dfs(len(coins) - 1, amount)
    return ans if ans < inf else -1
