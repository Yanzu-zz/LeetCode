class Solution:
  def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
    p = {(h, w): p for h, w, p in prices}
    dp = [[0 for _ in range(n+1)] for _ in range(m+1)]

    # 开始dp
    for i in range(1, m+1):
      for j in range(1, n+1):
        dp[i][j] = max(p.get((i, j), 0),
                       max((dp[i-k][j] + dp[k][j]
                           for k in range(1, m)), default=0),
                       max((dp[i][j-k] + dp[i][k] for k in range(1, n)), default=0))

    return dp[m][n]
