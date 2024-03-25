class Solution:
  def change(self, amount: int, coins: List[int]) -> int:
    @cache
    def dfs(i, remain):
      if i < 0:
        return 1 if remain == 0 else 0

      if remain < coins[i]:
        return dfs(i - 1, remain)

      return dfs(i-1, remain) + dfs(i, remain-coins[i])

    return dfs(len(coins) - 1, amount)
